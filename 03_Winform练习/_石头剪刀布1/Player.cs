﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _石头剪刀布1
{
    class Player
    {
        public int ShowFist(string fist)
        {
            int num = 0;
            switch (fist)
            {
                case "石头": num = 1;
                    break;
                case "剪刀": num = 2;
                    break;
                case "布": num = 3;
                    break;
                default:
                    break;
            }
            return num;
        }
    }
}
