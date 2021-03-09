/**
 * @file string-utils.h
 * @brief 字符串工具类，常用字符串操作
 * @author aydon (congtheking@outlook.com)
 * @version 1.0
 * @date 2020-11-18
 * 
 * @copyright Copyright (c) 2020 aydon
 */
#pragma once
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cctype>

namespace StringUtils
{
    using namespace std;

    template <class T>
    void Join(T begin, T end, string &res, const string &connector)
    {
        if (begin == end)
        {
            return;
        }
        stringstream ss;
        ss << *begin++;
        while (begin != end)
        {
            ss << connector << *begin++;
        }
        res = ss.str();
    }

    template <class T>
    string Join(T begin, T end, const string &connector)
    {
        string res;
        Join(begin, end, res, connector);
        return res;
    }

    template <class T>
    string Join(T src, const string &connector)
    {
        string res;
        Join(src.begin(), src.end(), res, connector);
        return res;
    }

    inline void Split(const string &src, vector<string> &res, const string &seg)
    {
        res.clear();
        size_t start = 0, found = 0, end = src.size();
        while (found != string::npos) {
            found = src.find(seg, start);
            cerr << found << endl;
            if (found != start && start != end) {
                res.emplace_back(src.substr(start, found - start));
            }
            start = found + seg.size();
        }
    }

    inline vector<string> Split(const string &src, const string &seg)
    {
        vector<string> res;
        Split(src, res, seg);
        return res;
    }

    inline string &ToUpper(string &src)
    {
        transform(src.begin(), src.end(), src.begin(), ::toupper);
        return src;
    }

    inline string &ToLower(string &src)
    {
        transform(src.begin(), src.end(), src.begin(), ::tolower);
        return src;
    }

    inline string &Capitalize(string &src)
    {
        transform(src.begin(), src.begin() + 1, src.begin(), ::toupper);
        return src;
    }

    inline string Center(string &src, size_t width, char fillchar = ' ')
    {
        stringstream ss;
        ssize_t len = width - src.size();
        len = len > 0 ? len : 0;

        size_t suffix = len / 2;
        size_t prefix = len - suffix + src.size();
        ss << setfill(fillchar) << setw(prefix) << src << setw(suffix) << "";
        return ss.str();
    }

    inline void Center(string &src, string &dst, size_t width, char fillchar = ' ')
    {
        dst = Center(src, width, fillchar);
    }

    inline size_t Count(const string &src, const string &sub, size_t start, size_t end)
    {
        end = end > src.size() ? src.size() : end;
        size_t count = 0;

        while (start != string::npos)
        {
            start = src.find(sub, start);
            if (start >= end)
            {
                break;
            }
            start += sub.size();
            count++;
        }
        return count;
    }

    inline size_t Count(const string &src, const string &sub)
    {
        return Count(src, sub, 0, src.size());
    }

    inline bool StartsWith(const string &src, const string &prefix)
    {
        if (prefix.size() > src.size())
        {
            return false;
        }

        return 0 == src.compare(0, prefix.size(), prefix);
    }

    inline bool EndsWith(const string &src, const string &suffix)
    {
        if (suffix.size() > src.size())
        {
            return false;
        }

        return 0 == src.compare(src.size() - suffix.size(), suffix.size(), suffix);
    }

    inline string Repeat(const string &str, unsigned int times)
    {
        stringstream ss;
        for (unsigned int i = 0; i < times; ++i)
        {
            ss << str;
        }
        return ss.str();
    }

    inline string Replace(const string &src, const string &target, const string &replacement)
    {
        return Join(Split(src, target), replacement);
    }

    inline string &Trim(string &src)
    {
        size_t begin = 0,
               end = src.size();
        for (size_t i = 0; i < src.size(); ++i)
        {
            if (!isspace(src[i]))
            {
                begin = i;
                break;
            }
        }

        for (size_t i = end - 1; i > 0; --i)
        {
            if (!isspace(src[i]))
            {
                end = i;
                break;
            }
        }

        if (begin >= end)
        {
            src = "";
        }
        else
        {
            src = src.substr(begin, end - begin + 1);
        }

        return src;
    }
} // namespace StringUtils
