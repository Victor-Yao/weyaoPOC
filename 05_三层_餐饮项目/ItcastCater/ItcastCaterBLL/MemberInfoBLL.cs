﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ItcastCater.Model;
using ItcastCater.DAL;

namespace ItcastCater.BLL
{
    public class MemberInfoBLL
    {
        MemberInfoDAL dal = new MemberInfoDAL();

        /// <summary>
        /// 保存新增或者修改会员的信息
        /// </summary>
        /// <param name="mem"></param>
        /// <param name="temp">1-> Add; 2-> Modify</param>
        /// <returns>成功或者失败</returns>
        public bool SaveMemberInfo(MemberInfo mem, int temp)
        {
            int r = -1;
            if (temp == 1)//新增
            {
                r = dal.AddMemberInfo(mem);
            }
            else if (temp == 2)//修改
            {
                r = dal.UpdateMemberInfo(mem);
            }

            return r > 0;
        }
        /// <summary>
        /// 根据id查对象
        /// </summary>
        /// <param name="id">会员的id</param>
        /// <returns>会员的对象</returns>
        public MemberInfo GetMemberInfoByMemberId(int id)
        {
            return dal.GetMemberInfoByMemberId(id);
        }
        /// <summary>
        /// 根据id修改会员的删除标识
        /// </summary>
        /// <param name="memberId"></param>
        /// <returns>是否更改成功</returns>
        public bool DeleteMemberInfoByMemberId(int memberId)
        {
            return dal.DeleteMemberInfoByMemberId(memberId) > 0 ? true : false;
        }

        /// <summary>
        /// 根据删除标志查询结果
        /// </summary>
        /// <param name="delFlag">0: 未删除;1: 删除</param>
        /// <returns></returns>
        public List<MemberInfo> GetAllMemberInfoByDelFlag(int delFlag)
        {
            return dal.GetAllMemberInfoByDelFlag(delFlag);
        }
    }
}
