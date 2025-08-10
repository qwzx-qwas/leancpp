#ifndef SCREEN_H
#define SCREEN_H
#include <string>

class Screen {
    public:
        typedef std::string::size_type pos;
        Screen() = default; // 默认构造函数
        Screen(pos ht, pos wd, char c = ' ') : height(ht), width(wd), 
        contents(ht * wd, c) { }
        char get() const { return contents[cursor]; } // 获取光标位置的字符
        inline char get(pos ht, pos wd) const; // 获取指定位置的字符
        Screen &move(pos r, pos c); // 移动光标到指定位置
        Screen &set(char);
        Screen &set(pos r, pos c, char ch);
    private:
        pos cursor = 0; // 光标位置
        pos height = 0; // 屏幕高度
        pos width = 0; // 屏幕宽度
        std::string contents; // 屏幕内容
};
inline
Screen &Screen::move(pos r, pos c) {
    pos row = r * width; // 计算行的起始位置
    cursor = row + c; // 更新光标位置
    return *this; // 返回当前对象的引用
}
char Screen::get(pos ht, pos wd) const {
    pos row = ht * width; // 计算行的起始位置
    return contents[row + wd]; // 返回指定位置的字符
}
inline Screen &Screen::set(char c) {
    contents[cursor] = c; // 设置光标位置的字符
    return *this; // 返回当前对象的引用
}
inline Screen &Screen::set(pos r, pos c, char ch) {
    pos row = r * width; // 计算行的起始位置
    contents[row + c] = ch; // 设置指定位置的字符
    return *this; // 返回当前对象的引用
}
#endif // SCREEN_H 
