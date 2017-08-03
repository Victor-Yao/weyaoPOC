﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Timers;

namespace _022_EventBasic
{
    public delegate void MessageHandler(string messageText);

    public class Connection
    {
        public event MessageHandler MessageArrived;
        private Timer pollTimer;

        public Connection()
        {
            pollTimer = new Timer(100);
            pollTimer.Elapsed += new ElapsedEventHandler(CheckForMessage);
        }

        public void Connect()
        {
            pollTimer.Start();
        }

        public void Disconnect()
        {
            pollTimer.Stop();
        }

        public static Random random = new Random();

        private void CheckForMessage(object sender, ElapsedEventArgs e)
        {
            Console.WriteLine("Checking for new Message.");
            if ((random.Next(9) == 0) && (MessageArrived != null))
            {
                MessageArrived("Hello Mum!");
            }
        }
    }
}
