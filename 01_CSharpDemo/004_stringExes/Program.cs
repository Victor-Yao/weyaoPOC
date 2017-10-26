﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace _004_stringExes
{
    class Program
    {
        static void Main(string[] args)
        {
            string path = @"C:\Users\Richard\Desktop\新建文本文档.txt";
            string[] contents= File.ReadAllLines(path,Encoding.Default);
            //string[] strContent = new string[2];
            string showContents;
            char[] chs = {'\t'};
            for (int i = 0; i < contents.Length; i++)
            {
                string[] strContent = contents[i].Split(chs, StringSplitOptions.RemoveEmptyEntries);
                if (strContent[0].Length >= 10)
                {
                    showContents = strContent[0].Substring(0, 8);
                    showContents += "...";
                }
                else 
                {
                    showContents = strContent[0];
                }
                showContents= showContents+"-"+strContent[1];
                Console.WriteLine(showContents);
            }
            Console.ReadKey();
        }

        //20.将字符串"  hello      world,你  好 世界   !    "两端空格去掉，并且将其中的所有其他空格都替换成一个空格，
        //输出结果为："hello world,你 好 世界 !"。
        public static void LianXi_20()
        {
            string str = "  hello      world,你  好 世界   !    ";
            string[] strArray = str.Split(' ');
            string result = "";

            for (int i = 0; i < strArray.Length; i++)
            {
                if ("" != strArray[i])
                {
                    result += strArray[i] + " ";
                }
            }
            result.TrimEnd();
            Console.WriteLine(result);
        }

        //要求：用户可以在控制台录入每个学生的姓名，当用户输入quit（不区分大小写）时，程序停止接受用户的输入，
        //并且显示出用户输入的学生的个数，以及每个学生的姓名。
        public static void LianXi_21()
        {
            List<string> list = new List<string>();
            string str = "";

            while (true)
            {
                Console.WriteLine("请输入姓名：");
                str = Console.ReadLine();
                if (str.Equals("quit", StringComparison.OrdinalIgnoreCase))
                {
                    break;
                }
                list.Add(str);
            }
            Console.WriteLine("用户输入的学生个数：{0}", list.Count);

            for (int i = 0; i < list.Count; i++)
            {
                Console.WriteLine(list[i]);
            }
        }

        //再增加一个显示姓“王”的同学的个数，此处不考虑复姓问题。
        public static void LianXi_22()
        {
            List<string> list = new List<string>();
            string str = "";

            while (true)
            {
                Console.WriteLine("请输入姓名：");
                str = Console.ReadLine();
                if (str.Equals("quit", StringComparison.OrdinalIgnoreCase))
                {
                    break;
                }
                list.Add(str);
            }
            Console.WriteLine("用户输入的学生个数：{0}", list.Count);

            int num = 0;
            for (int i = 0; i < list.Count; i++)
            {
                Console.WriteLine(list[i]);
                if (list[i].StartsWith("王"))
                {
                    num++;
                }
            }

            Console.WriteLine("姓王的同学人数：{0}", num);
        }

        //将字符串数组{ "中国", "美国", "巴西", "澳大利亚", "加拿大" }中的内容反转。然后输出反转后的数组。
        public static void LianXi_23()
        {
            string[] strArray = { "中国", "美国", "巴西", "澳大利亚", "加拿大" };
            string temp = "";
            for (int i = 0; i < strArray.Length / 2; i++)
            {
                temp = strArray[i];
                strArray[i] = strArray[strArray.Length - i - 1];
                strArray[strArray.Length - i - 1] = temp;
            }
            for (int i = 0; i < strArray.Length; i++)
            {
                Console.Write(strArray[i] + "\t");
            }

        }
    }
}
