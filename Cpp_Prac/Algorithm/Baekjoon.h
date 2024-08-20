#pragma once

//#define EqualString
#ifdef EqualString
#include <string>
/// <param name="a_source"> abcde </param>
/// <param name="a_find"> de </param>
/// <returns> true </returns>
bool isEqualEndString(std::string a_source, std::string a_find)
{
	return a_source.compare(a_source.length() - a_find.length(), a_find.length(), a_find) == 0;
	return a_find == a_source.substr(a_source.length() - a_find.length(), a_find.length());
}

bool isEqualStartString(const std::string& a_source, const std::string& a_find)
{
	return a_source.compare(0, a_find.length(), a_find) == 0;
}
#endif

//#define EraseComments
#ifdef EraseComments
#include <cstring>
#include <string>
#include <sstream>
#include <regex>

using namespace std;
/// <param name="start"> 
/// "int main() {\n\tint hi; // 1) comment\n\tint hello; /* 2) comment */\n\n\n\tint ciao; /* 6) comment\n*\n*\n*\n*\n*/\n// 9) comment /*\n\n\n\tint isNotAComment;\n/* 10) comment\n//\n*/\tint i = 9; // 11) comment\n}\n"
/// </param>
/// <returns> 
/// "int main() {[\n]\tint hi; [\n]]tint hello; [\n][\n][\n]\tint ciao; [\n][\n]}[\n]"
/// </returns>
std::string eraseComments(std::string start) {
#ifdef _Ethan // Ʋ��.. �� ������ [\n]�����ȵ�...
	//// 1-1. ���ڿ����� "/*" ��ġ ã��
	//// 1-2. ó�� ���� "/*" ���ĺ��� "*/"���� ��ġ ã��
	//// 1-3. �߰� �κ� ����
	//// 1-4. �ݺ�
	//// 
	//// 2-1. ���ڿ����� "//" ����, ��ġ ã��
	//// 2-2. // ���� /n ���๮�ڱ��� ���ڿ� ����
	//// 2-3. �ݺ�
	int commentStart, commentEnd;
	std::string subsFirst;

	while (start.find("/*") != -1)
	{
		commentStart = start.find("/*");
		commentEnd = start.find("*/");
		subsFirst = start.substr(commentEnd + 2, start.length() - commentEnd);
		start.replace(commentStart, start.length() - commentStart, subsFirst);
	}
	while (start.find("//") != -1)
	{
		commentStart = start.find("//");
		commentEnd = start.find("\n", commentStart);
		start.erase(commentStart, commentEnd - commentStart);
	}

	commentStart = 0;
	while (start.find("\n", commentStart + 2) != -1)
	{
		commentStart = start.find("\n", commentStart + 2);
		start.replace(commentStart, 1, "\\n");
	}

	commentStart = 0;
	while (start.find("\t", commentStart + 2) != -1)
	{
		commentStart = start.find("\t", commentStart + 2);
		start.replace(commentStart, 1, "\\t");
	}
	return start; // 
#endif

#ifdef _Regex
    int k = 0;
    start = regex_replace(start, regex("\n( *\t*)*\n"), "\n\n");
    for (int i = 0; i < start.size(); i++)
    {
        if (start[i] == '/' and i + 1 < start.size() and start[i + 1] == '*')
        {
            k = i;
            while (not(start[k] == '*' and k + 1 < start.size() and start[k + 1] == '/'))
            {
                if (start[k] == '\n' and start[k + 1] == '\n')
                {
                    start[k + 1] = '$';
                    start[k] = '$';
                }
                else if (start[k] == '$' and start[k + 1] == '\n')
                {
                    start[k + 1] = '$';
                }
                else if (start[k] != '$')
                    start[k] = '|';
                k += 1;
            }
            start[k] = '|';
            start[k + 1] = '|';
        }
        else if (start[i] == '/' and i + 1 < start.size() and start[i + 1] == '/')
        {
            k = i;
            int flag = 0;
            while (start[k] != '\n' or flag)
            {
                flag = 0;
                if (start[k] == '\\' and start[k + 1] == '\n')
                    flag = 1;
                start[k] = '|';
                k += 1;
            }
            for (int p = k - 1; p >= 0; p--)
            {
                if (start[p] == '\n')
                {
                    if (start[p + 1] == '|' and k != 188)
                        start[k] = '|';
                    break;
                }
            }
        }
    }
    string d = regex_replace(regex_replace(start, regex("\\|+"), ""), regex("\\$"), "\n");
    if (d[d.size() - 1] != '\n')
        d += "\n";
    return d;
#endif
}
#endif

#define NO1463
#ifdef NO1463
#include <string>
/// <summary>
/// ���� X�� ����� �� �ִ� ������ ������ ���� �� ���� �̴�.
/// 1. X�� 3���� ������ ��������, 3���� ������.
///  -> 1����
/// 2. X�� 2�� ������ ��������, 2�� ������.
///  -> 2����
/// 3. 1�� ����.
///  ���� N�� �־����� ��, ���� ���� ���� �� ���� ������ ����ؼ� 1�� ������� �Ѵ�. ������ ����ϴ� Ƚ���� �ּڰ��� ����Ͻÿ�.
/// </summary>
int MakeNumberOne(int N)
{
    static int ret = 0;
    if (N % 3 == 0)
    {
        N /= 3; ret++;
    }
    
    else if (N % 2 == 0)
    {
        N /= 2; ret++;
    }
    else
    {
        N -= 1;
        ret++;
    }

    if (N == 1)
    {
        int temp = ret;
        ret = 0;
        return temp;
    }
    else
        return MakeNumberOne(N);
}
#endif
