#!/usr/bin/env bash

set -e  # 出错立即退出
ROOT_DIR="$(cd "$(dirname "$0")" && pwd)"
SRC_DIR="$ROOT_DIR/src"
TEST_DIR="$ROOT_DIR/test"
INC_DIR="$ROOT_DIR/include"
BUILD_DIR="$ROOT_DIR/build"
MAIN_FILE="$ROOT_DIR/main.c"

mkdir -p "$SRC_DIR" "$TEST_DIR" "$INC_DIR"

# ---------- 工具函数 ----------
log() { echo -e "\033[1;36m$1\033[0m"; }
warn() { echo -e "\033[1;33m$1\033[0m"; }
error() { echo -e "\033[1;31m$1\033[0m" >&2; }

# ---------- 🚫 保留名检测 ----------
is_reserved_name() {
  local module=$1
  local reserved="string stdio stdlib math time assert signal setjmp locale ctype wchar errno limits float complex tgmath fenv iostream vector map list algorithm random thread"
  for name in $reserved; do
    if [[ "$module" == "$name" ]]; then
      return 0
    fi
  done
  return 1
}

# ---------- 1️⃣ 创建模块 ----------
create_module() {
  local module=$1
  if [ -z "$module" ]; then
    error "❌ 缺少模块名：用法 ./pee.sh create <module>"
    exit 1
  fi

  # 检测模块名是否合法
  if is_reserved_name "$module"; then
    error "❌ 模块名 '$module' 与系统库冲突，请换个名字！"
    exit 1
  fi

  mkdir -p "$SRC_DIR/$module" "$TEST_DIR" "$INC_DIR"

  local header_file="$INC_DIR/${module}.h"
  if [ ! -f "$header_file" ]; then
    cat > "$header_file" <<EOF
#ifndef ${module^^}_H
#define ${module^^}_H

#endif
EOF
    log "✅ 创建头文件: include/${module}.h"
  else
    warn "⚠️ 头文件已存在: include/${module}.h"
  fi

  log "✅ 模块创建完成: $module"
}

# ---------- 2️⃣ 添加算法 ----------
add_algorithm() {
  local module=$1
  local algo=$2
  if [ -z "$module" ] || [ -z "$algo" ]; then
    error "❌ 缺少参数：用法 ./pee.sh add <module> <algorithm>"
    exit 1
  fi

  # 检查模块是否存在
  if [ ! -d "$SRC_DIR/$module" ]; then
    error "❌ 模块 '$module' 不存在，请先执行 ./pee.sh create $module"
    exit 1
  fi

  local src_file="$SRC_DIR/$module/${algo}.c"
  local header_file="$INC_DIR/${module}.h"
  local test_file="$TEST_DIR/test_${module}.c"

  # 算法实现
  cat > "$src_file" <<EOF
#include "${module}.h"
#include <stdio.h>

void ${algo}(void) {
    printf("Running ${algo}...\\n");
}
EOF
  log "🧩 源文件已生成: src/${module}/${algo}.c"

  # 头文件声明
  if ! grep -q "void ${algo}(void);" "$header_file"; then
    sed -i "/#endif/i void ${algo}(void);" "$header_file"
    log "🔗 已更新头文件声明: include/${module}.h"
  fi

  # 测试文件
  if [ ! -f "$test_file" ]; then
    cat > "$test_file" <<EOF
#include <stdio.h>
#include "${module}.h"

void test_${module}(void) {
    printf("Testing module: ${module}\\n");
    ${algo}();
}
EOF
  else
    sed -i "/}/i \    ${algo}();" "$test_file"
  fi
  log "🧪 测试文件更新: test/test_${module}.c"

  # 注册到 main.c
  if [ -f "$MAIN_FILE" ]; then
    if ! grep -q "test_${module}" "$MAIN_FILE"; then
      sed -i "/int main/a \    test_${module}();" "$MAIN_FILE"
      sed -i "/#include <stdio.h>/a void test_${module}(void);" "$MAIN_FILE"
      log "📎 已自动注册到 main.c"
    fi
  else
    cat > "$MAIN_FILE" <<EOF
#include <stdio.h>
void test_${module}(void);

int main(void) {
    printf("=== PEECode Test Runner ===\\n");
    test_${module}();
    return 0;
}
EOF
    log "🧱 已创建 main.c 并注册 test_${module}"
  fi
}

# ---------- 3️⃣ 编译 + 运行 ----------
run_project() {
  mkdir -p "$BUILD_DIR"
  cd "$BUILD_DIR"
  log "🛠️  生成构建文件..."
  cmake -G "MinGW Makefiles" .. >/dev/null
  log "⚙️  正在编译..."
  cmake --build . >/dev/null
  log "✅ 编译完成"
  exe="$BUILD_DIR/bin/pee_code.exe"
  if [ -f "$exe" ]; then
    log "🚀 运行结果:"
    "$exe"
  else
    error "❌ 没找到可执行文件"
  fi
}

# ---------- 4️⃣ 清理 ----------
clean_project() {
  rm -rf "$BUILD_DIR"
  log "🧹 已清理 build 目录"
}

# ---------- 主逻辑 ----------
case "$1" in
  create)
    create_module "$2"
    ;;
  add)
    add_algorithm "$2" "$3"
    ;;
  run)
    run_project
    ;;
  clean)
    clean_project
    ;;
  *)
    echo "用法:
  ./pee.sh create <module>
  ./pee.sh add <module> <algorithm>
  ./pee.sh run
  ./pee.sh clean"
    ;;
esac

