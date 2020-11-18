# StringUtils

实现常用字符串操作函数。例如 `Split`, `Join`, `Trim`, `Count`, `Replace`, `ToLower`, `ToUpper` 等。

![](https://img.shields.io/badge/language-c%2B%2B-blue)

## 如何使用

该项目为 header-only 文件，因此只需在文件中包含头文件即可。

### Makefile 使用

```makefile
CXXFLAGS += -I/path/to/string-utils.h
```

### CMake 使用

```cmake
include_directories(/path/to/string-utils-dir)
```

### 接口说明

函数原型|说明
--|--
void Join(T begin, T end, string &res, const string &connector) | 合并为一个字符串，合并标识符为 connector
string Join(T begin, T end, const string &connector) | 同上，重载函数
string Join(T src, const string &connector) | 同上，重载函数
void Split(const string &src, vector<string> &res, const string &seg) | 按照 seg 切分字符串
vector<string> Split(const string &src, const string &seg) | 同上，重载函数
string &ToUpper(string &src) | 将字符串全转为大小字母
string &ToLower(string &src) | 将字符串全转为小写字母
string &Capitalize(string &src) | 将字符串首字母转为大写字母
string Center(string &src, size_t width, char fillchar = ' ') | 字符串居中显示，多余部分使用 fillchar 填充
void Center(string &src, string &dst, size_t width, char fillchar = ' ') | 同上，重载函数
size_t Count(const string &src, const string &sub, size_t start, size_t end) | 计算子字符串出现的次数
size_t Count(const string &src, const string &sub) | 同上，重载函数
bool StartsWith(const string &src, const string &prefix) | 判断字符串是否是以 prefix 开始
bool EndsWith(const string &src, const string &suffix) | 判断字符串是否是以 suffix 结尾
string Repeat(const string &str, unsigned int times) | 复制多次字符串
string Replace(const string &src, const string &target, const string &replacement) | 替换字符串中的字符
string &Trim(string &src) | 去除字符串首尾空格