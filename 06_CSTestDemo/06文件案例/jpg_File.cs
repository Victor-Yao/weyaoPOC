﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _06文件案例
{
    public class jpg_File : CustomFile
    {
        public override string OpenFile()
        {
            return "用图片查看器打开文件";
        }
    }
}
