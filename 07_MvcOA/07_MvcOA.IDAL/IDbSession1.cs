﻿ 

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _07_MvcOA.IDAL
{
	public partial interface IDBSession
    {
	
		IActionInfoDal ActionInfoDal{get;set;}
	
		IBookDal BookDal{get;set;}
	
		IDepartmentDal DepartmentDal{get;set;}
	
		IKeywordsRankDal KeywordsRankDal{get;set;}
	
		IR_UserInfo_ActionInfoDal R_UserInfo_ActionInfoDal{get;set;}
	
		IRoleInfoDal RoleInfoDal{get;set;}
	
		ISearchDetailsDal SearchDetailsDal{get;set;}
	
		IUserInfoDal UserInfoDal{get;set;}
	}	
}