﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using ItcastCater.Model;
using ItcastCater.BLL;

namespace ItcastCater
{
    public partial class FrmMain : Form
    {
        public FrmMain()
        {
            InitializeComponent();
        }

        private void btnMemberInfo_Click(object sender, EventArgs e)
        {
            var frmMenbenInfo = new FrmMemberInfo();
            frmMenbenInfo.ShowDialog();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            var frmCategory = new FrmCategroy();
            frmCategory.ShowDialog();
        }

        private void FrmMain_Load(object sender, EventArgs e)
        {
            LoadRoomInfoByDelFlag(0);
            LoadDeskInfoBySelectedRoomId(tabc.TabPages[0]);
        }

        //加载餐桌
        private void LoadDeskInfoBySelectedRoomId(TabPage tp)
        {
            var rm = tp.Tag as RoomInfo;
            var lv = tp.Controls[0] as ListView;//lv对象储存在tabPage中
            lv.Clear();
            var bll = new DeskInfoBLL();
            var listDesk = bll.GetAllDeskInfoByRoomId((int)rm.RoomId);
            for (int i = 0; i < listDesk.Count; i++)
            {
                lv.Items.Add(listDesk[i].DeskName, (int)listDesk[i].DeskState);
                lv.Items[i].Tag = listDesk[i];
            }
        }

        //加载所有房间
        private void LoadRoomInfoByDelFlag(int p)
        {
            var bll = new RoomInfoBLL();
            var listRoom = bll.GetAllRoomInfoByDelFlag(p);
            foreach (var room in listRoom)
            {
                var tp = new TabPage();
                tp.Text = room.RoomName;
                tp.Tag = room;//将房间对象储存到tag属性中

                var lv = new ListView();
                lv.LargeImageList = imageList1;//绑定图片
                lv.View = View.LargeIcon;//图片显示的方式
                lv.Dock = DockStyle.Fill;//设置填充方式
                lv.MultiSelect = false;//禁止多选
                lv.BackColor = Color.Tan;
                tp.Controls.Add(lv);//将lv添加到tabPage中
                tabc.TabPages.Add(tp);//将tp添加到tabControl中
            }
        }

        private void tabc_SelectedIndexChanged(object sender, EventArgs e)
        {
            var tpc = sender as TabControl;
            LoadDeskInfoBySelectedRoomId(tpc.SelectedTab);
        }

        public event EventHandler evtFbi;
        private void btnBilling_Click(object sender, EventArgs e)
        {
            var tb = tabc.SelectedTab;
            var lv = tb.Controls[0] as ListView;

            if (lv.SelectedItems.Count <= 0)
            {
                MessageBox.Show("请选择餐桌");
                return;
            }

            if ((lv.SelectedItems[0].Tag as DeskInfo).DeskState != 0)
            {
                MessageBox.Show("请选择未开单的餐桌");
                return;
            }

            var mea = new MyEventArgs();
            mea.Obj = lv.SelectedItems[0].Tag;//传递DeskInfo
            mea.Name = (tb.Tag as RoomInfo).RoomName;
            mea.Money = Convert.ToDecimal((tb.Tag as RoomInfo).RoomMinimunConsume);//房间的最低消费

            var fbi = new FrmBilling();
            this.evtFbi += new EventHandler(fbi.SetText);
            if (this.evtFbi!=null)
            {
                this.evtFbi(this, mea);
                fbi.FormClosed += new FormClosedEventHandler(fbi_FormClosed);
                fbi.ShowDialog();
            }
        }

        //开单后刷新餐桌
        private void fbi_FormClosed(object sender, FormClosedEventArgs e)
        {
            LoadDeskInfoBySelectedRoomId(tabc.SelectedTab);
        }
    }
}
