﻿<%@ WebHandler Language="C#" Class="_04_UserInfoList" %>

using System;
using System.Web;
using System.Data;
using System.Data.SQLite;
using System.Data.SqlClient;
using System.Text;
using System.IO;
using SqliteCURD;

public class _04_UserInfoList : IHttpHandler
{

    public void ProcessRequest(HttpContext context)
    {
        context.Response.ContentType = "text/html";

        #region Implement retrive database by SqlServer
        var conStr = System.Configuration.ConfigurationManager.ConnectionStrings["connStr"].ConnectionString;
        using (var con = new SqlConnection(conStr))
        {

            using (var sda = new SqlDataAdapter("select EmployeeID,FirstName,PostalCode,HireDate,HomePhone from Employees", con))
            {
                var dt = new DataTable();
                sda.Fill(dt);

                var sb = new StringBuilder();
                if (dt.Rows.Count>0)
                {
                    foreach (DataRow dr in dt.Rows)
                    {
                        sb.AppendFormat("<tr><td>{0}</td><td>{1}</td><td>{2}</td><td>{3}</td><td>{4}</td><td><a href='06_ShowDetail.ashx?id={5}'>详细</a></td><td><a href='07_DeleteDetail.ashx?id={5}'>删除</a></td></tr>", dr["EmployeeID"], dr["FirstName"], dr["PostalCode"], Convert.ToDateTime(dr["HireDate"]).ToShortDateString(),dr["HomePhone"],dr["EmployeeID"]);
                    }
                }
                else
                {
                    context.Response.Write("未查询到数据");
                }

                var filePath = context.Request.MapPath("04_UserInfoList.html");
                var fileContent = File.ReadAllText(filePath);
                fileContent = fileContent.Replace("$tbody", sb.ToString());
                context.Response.Write(fileContent);
            }
        }
        #endregion

        #region .... by SqliteHelper.dll
        //var sql = "select MemmberId,MemName,MemMobilePhone,MemBirthdaty from UserInfo";
        //var dt = SqliteHelper.ExecuteTable(sql);

        //if (dt.Rows.Count > 0)
        //{
        //    foreach (DataRow dr in dt.Rows)
        //    {
        //        var sb = new StringBuilder();
        //        sb.AppendFormat("<tr><td>{0}</td><td>{1}</td><td>{2}</td><td>{3}</td><td>{4}</td><td><a href='ShowDetail.ashx?id={5}'>详细</a></td></tr>", dr["MemmberId"], dr["MemName"], dr["MemMobilePhone"], Convert.ToDateTime(dr["MemBirthdaty"]).ToShortDateString());

        //        var filePath = context.Request.MapPath("UserInfoList.html");
        //        var fileContent = File.ReadAllText(filePath);
        //        fileContent = fileContent.Replace("$tbody", sb.ToString());
        //        context.Response.Write(fileContent);
        //    }
        //}
        #endregion
    }

    public bool IsReusable
    {
        get
        {
            return false;
        }
    }

}