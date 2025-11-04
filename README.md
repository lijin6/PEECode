## 🧩 PEECode — Postgraduate Entrance Examination Code Framework

> **“让考研 408 的代码测试变得像写笔记一样轻松。”**
> 作者：Brook | 环境：C + CMake + MinGW | 平台：VSCode + 命令行

---

### 💡 项目背景

在考研复习中，尤其是 **408 数据结构与操作系统**，我们会不断手写各种算法和结构（如排序、查找、栈、树、图等）。

但每写一个函数都要：

* 新建 `.c` / `.h` 文件
* 手动修改 `main()` 测试
* 重新配置 CMake
* 编译运行

💥 繁琐又容易出错。

---

### 🚀 解决方案：PEECode

**PEECode** 是一个为考研算法设计的自动化测试框架，使用一套 Bash 脚本让你：

| 操作             | 命令                                  |
| -------------- | ----------------------------------- |
| 创建新模块（如排序、链表等） | `./pee.sh create <module>`          |
| 添加算法实现         | `./pee.sh add <module> <algorithm>` |
| 一键编译运行         | `./pee.sh run`                      |
| 清理构建目录         | `./pee.sh clean`                    |

无需再手动改 `main.c`，每个算法都会自动注册到主函数中并运行测试。

---

### 🧩 项目结构

```
PEECode/
├── include/              # 头文件目录
│   ├── sort.h
│   └── linear_list.h
│
├── src/                  # 源代码目录
│   ├── sort/
│   │   ├── bubble_sort.c
│   │   └── quick_sort.c
│   └── linear_list/
│       └── linked_list.c
│
├── test/                 # 模块测试代码
│   ├── test_sort.c
│   └── test_linear_list.c
│
├── main.c                # 主入口（自动更新）
├── pee.sh                # 自动化构建脚本
├── CMakeLists.txt        # CMake 配置
└── README.md
```

---

### ⚙️ 使用示例

#### ✅ 1. 创建新模块

```bash
./pee.sh create sort
```

输出：

```
✅ 创建头文件: include/sort.h
✅ 模块创建完成: sort
```

#### ✅ 2. 添加算法实现

```bash
./pee.sh add sort bubble_sort
```

输出：

```
🧩 源文件已生成: src/sort/bubble_sort.c
🔗 已更新头文件声明: include/sort.h
🧪 测试文件更新: test/test_sort.c
📎 已自动注册到 main.c
```

你可以直接在生成的 `src/sort/bubble_sort.c` 中写自己的代码。

#### ✅ 3. 运行测试

```bash
./pee.sh run
```

输出示例：

```
=== PEECode Test Runner ===
After sort: 1 2 3 4 5
```

---

### 🧱 特点

* 🧩 **模块化组织**：每个知识点独立成模块，结构清晰
* 🔄 **自动注册**：`main.c` 无需手改，自动插入测试调用
* ⚙️ **一键编译**：基于 CMake + MinGW
* 🧹 **快速清理**：`./pee.sh clean` 即可重构
* 🧠 **学习导向**：特别适配考研 408 的数据结构与算法题

---

### 📚 典型模块示例

| 模块            | 算法/内容        |
| ------------- | ------------ |
| `sort`        | 冒泡、快速、归并排序   |
| `linear_list` | 顺序表、链表操作     |
| `stack`       | 顺序栈、链栈、括号匹配  |
| `tree`        | 二叉树、遍历、深度统计  |
| `graph`       | DFS、BFS、最短路径 |
| `os`          | 银行家算法、页面置换   |

---

### ⚠️ 注意事项

* 模块名 **不能与标准库冲突**（如 `string`、`math`、`stdio` 等）
* 每次添加算法后，请使用 `./pee.sh run` 测试是否自动注册成功
* 推荐使用 **VSCode + CMake Tools** 插件查看源码结构

---

### 🧠 下一步计划

| 目标          | 内容             |
| ----------- | -------------- |
| ✅ 基础算法自动管理  | 已完成            |
| 🔧 自动单元测试系统 | 基于 CTest       |
| 💾 数据结构可视化  | Graphviz 输出结构图 |
| 🧩 AI 模块扩展  | 自动生成算法注释与思路    |
| 🚀 云端同步     | 可与 GitHub 自动备份 |

---

### ❤️ 结语

> “我不只是想通过考研，我想用代码去理解算法本身。”
> — Brook

---
