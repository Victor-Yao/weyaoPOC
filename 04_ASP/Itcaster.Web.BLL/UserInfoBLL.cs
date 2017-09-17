﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Itcaster.Web.Model;
using Itcaster.Web.DAL;

namespace Itcaster.Web.BLL
{
    public class UserInfoBLL
    {
        UserInfoDAL dal = new UserInfoDAL();

        /// <summary>
        /// Get an UserInfo
        /// </summary>
        /// <param name="id"></param>
        /// <returns></returns>
        public UserInfo GetEntityModel(int id)
        {
            return dal.GetEntityModel(id);
        }

        /// <summary>
        /// detele an UserInfo
        /// </summary>
        /// <param name="id"></param>
        /// <returns></returns>
        public bool DeleteEntityModel(int id)
        {
            return dal.DeleteEntityModel(id) > 0;
        }

        /// <summary>
        /// Edit an UserInfo
        /// </summary>
        /// <param name="userInfo"></param>
        /// <returns></returns>
        public bool UpdateEntityModel(UserInfo userInfo)
        {
            return dal.UpdateEntityModel(userInfo) > 0;
        }

        /// <summary>
        /// Insert a new UserInfo
        /// </summary>
        /// <param name="userInfo"></param>
        /// <returns></returns>
        public bool InsertEntityModel(UserInfo userInfo)
        {
            return dal.InsertEntityModel(userInfo) > 0;
        }

        /// <summary>
        /// Get all userinfo
        /// </summary>
        /// <returns></returns>
        public List<UserInfo> GetEntityList()
        {
            return dal.GetEntityList();
        }
    }
}
