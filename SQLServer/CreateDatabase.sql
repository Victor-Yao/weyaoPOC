
Create Table class
(
	classId int identity(1,1) primary key,
	className nvarchar(10) not null,
	classDesc nvarchar(50)
)
select * from DeskInfo
--��������ţ���Ϣ����ע����ʾ��ʱ��
Create Table Desk
(
	DeskId int identity(1,1) primary key,
	DeskNum nvarchar(10),
	DeskInfo nvarchar(10),
	DeskRemark nvarchar(20),
	Flag int,
	DeskSetTime Datetime
)
use TestDB

select * from Desk
select * from class

--����1��ע�ⷵ��ֵ
Insert into ����(��1,��2) values(ֵ1,ֵ2)
insert into class(className,classDesc) values('���ж���','����һ����')
--����2������3��������Ӷ�������
insert into class values('����һ��','������')
insert into class values('��������','���Ǻ���')
--����4,N���ڽ��������������
insert into class(className,classDesc)
select N'����1-3','��������' union
select '����4-6','�е�����' union
select '����7��','��������'

select * from class
--��������,����ֵΪ��Ӱ�������

update ���� set ��1 = ֵ1
update class set classDesc = '��������'
update class set classDesc = '�Ƚ�����' where classId = 1 or classId = 6
update class set classDesc = '�Ƚ�����' where classId = 1

--�л����ݿ�
use TestDB
select * from class
insert into class values('���ж���','����һ����')
--ɾ��
--����1��ֻɾ�����ݣ�ID��ɾ��ǰ��ID��ʼ+1
delete from class
delete from class where classId = 10
--����2��ɾ�����ű����ײ�ʹ��
drop table Desk
--����3��ɾ������,ID��1��ʼ
truncate table class

create table Employees
(
	EmpId int identity(1,1),
	EmpName varchar(50),
	EmpGender char(2),
	EmpAge int,
	EmpEmail varchar(100),
	EmpAddress varchar(500)
)


create table Department
(
	DepId int identity(1,1) primary key,
	DepName varchar(50) unique not null	
)

----Lesson 2
--��ϰ
--�ֶ�ɾ��һ��(ɾ��EmpAddress��)
alter table Employees drop column EmpAddress
alter table Employees drop column DeptID
--�ֶ�����һ��(����һ��EmpAddr varchar(1000))
alter table Employees add EmpAddr nvarchar(50)
--�ֶ��޸�һ��EmpEmail����������(varchar(200))
alter table Employees alter column EmpEmail varchar(200)
--ΪEmpId����һ������Լ��
alter table Employees add constraint PK_Employees_EmpID primary key(EmpID)
alter table Employees add constraint PK_Employees_EmpID primary key(EmpID)
--�ǿ�Լ��,ΪEmpName����һ���ǿ�Լ��
alter table Employees alter column DeptID int not null
--ΪEmpName����һ��ΨһԼ��
alter table Employees add constraint UQ_Employees_EmpAge unique (EmpName)
Insert into Employees values ('zhan','��',12,'123@123.com',1,'beijing')
--Ϊ�Ա�����һ��Ĭ��Լ����Ĭ��Ϊ'��'
alter table Employees add constraint DF_Employees_EmpGender default ('��') for EmpGender
--Ϊ��������һ�����Լ�������������1-120��֮�䣬�������ꡣ
alter table Employees add constraint CK_Employees_EmpAge check (EmpAge>=1 and EmpAge<=120)
--����һ�����ű�Ȼ��ΪEmployee������һ��DepId�С�
alter table Employees add DepId int not null
select * from Employees
--�������Լ��
alter table Employees add constraint FK_Employees_DepId foreign key(DepId) references Department(DepId)
--ֻ������Ҫ����
Select EmpName, EmpAge from Employees
--����1
Select EmPname as 'Ա������', EmpAge as '����' from Employees
--����2
Select EmPname as Ա������, EmpAge as ���� from Employees
--����3
Select Ա������=EmpName, ����=EmpAge from Employees
--��������
Select EmPname as 'Ա������', EmpAge as '����' from Employees where EmpGender = 1

Select 100+1
Select GETDATE()
print 100+90
print '��ǰʱ��'+getdate()---�ַ�����ʱ���ʽװ��������

--����
--��ѯ�������ݵ�ǰ10������
Select top 10* from Employees
--��ѯ������С��5��ѧ������Ϣ
Select top 5* from Employees order by EmpAge --Ĭ������������asce
--�Ӵ�С���򣬲�ѯ�����������İٷ�֮10��ѧ����Ϣ
Select top 10 percent * from Employees order by EmpAge desc --��������
--��Ӣ��ɼ����򣬲��е�����ѧ�ɼ�����������
Select * from tblScore where order by tsEnglish desc, order by tsMath desc

Select*, �ܳɼ� = (tsenglish + tsmath) from tblScore where order by (tsEnglish +tsMath) desc
--ȥ���ظ� distinct�ڲ�ѯ�����ȥ���ظ���������������ĳһ��
Select distinct EmpName from Employees

--SQL�ۺϺ���:MAX, MIN, AVG, SUM, COUNT, null������ۺϺ���������
--��ѯ�ж���������
select COUNT(*) from Employees
--��ѯ��ߵ���ѧ�ɼ�
select MAX(tsmath) from tblScore
--��ѯ��ѧ�ɼ���ߵ��˵�Ӣ��ɼ�
select top 1 tsenglish, math from tblScore order by tsmath desc
--��ѯ��͵���ѧ�ɼ�
select MIN(tsmath) from tblScore
--������ѧ�ɼ����ܺ�
select SUM(tsmath) from tblScore
--����ƽ��ֵ
select AVG(tsmath) from tblScore
--��ʾӢ��ɼ������ֵ��ƽ��ֵ���ܺ�
select MAX(tsenglish) as '���ֵ', AVG(tsenglish) as 'ƽ��ֵ', SUM(tsenglish) as '�ܺ�' from tblScore

--С�����ܽ᣺
--1������*��������,�����еĲ�ѯ�ٶ��б�*��
select * from table
select ������ from table 
--2�����У����԰��ؼ��ֻ��У���Ӱ�����㡣�����д
select 
MAX(tsenglish) as '���ֵ', 
AVG(tsenglish) as 'ƽ��ֵ', 
SUM(tsenglish) as '�ܺ�' 
from tblScore
--3��null�Ƿ������*������,COUNT(*)����null,COUNT(����)������
select  COUNT(*) from tblScore
select COUNT(tsEnglish) from tblScore

--��ѯ��ʹ���20С��30������, betweenЧ�ʸ���
select * from Employees where EmpAge>20 and EmpAge<30 and EmpGender = 1
select * from Employees where EmpGender = 1 and EmpAge Between 20 and 30

--��ѯԱ�����Ϊ1,2,3��Ա��,���ַ���
select * from Employees where EmpId = 1 or EmpId = 2 or EmpId = 3
select * from Employees where EmpId in (1,2,3)

--ģ����ѯ��ͨ���%, _, []�����ڹؼ�������, ^(ֻ��MSSQLSERVER֧�֣�����DBMS��not like)
--�����������ŵ���������
select * from Employees where EmpName like '��%'
--�ź����һ����
select * from Employees where EmpName like '��_'
--�ź����������
select * from Employees where EmpName like '��__'
select * from Employees where EmpName like '��%' and LEN(EmpName) = 3
--��������ĸ������
select * from Employees where EmpName like '��[a-z]%'
--����������ŵ�
select * from Employees where EmpName like '%��%'
--���ŵ�����������ٷֺŵ�
select * from Employees where EmpName like '��[%]%'
select * from Employees where EmpName like '��[_]%'
--���ŵ������������������
select * from Employees where EmpName like '��[0-9]%'
select * from Employees where EmpName like '��[^0-9]_'

--��ֵ����,null��֪��,�ж��ǲ���mull
select * from Employees where EmpAge is null
select * from Employees where EmpAge is not null

--����
--��ѯÿ���༶��������
select tclassid as '�༶', COUNT(*) as '����' from student group by tclassid
--��ѯÿ���༶����ͬѧ������
select tclassid as '�༶', COUNT(*) as '����' from student where Gender = 1 group by tclassid
--����ɸѡ��having
select tclassid as '�༶', COUNT(*) as '����' from student group by tclassid
having count(*)>3

--��order���в�ѯ
--1.��������Ʒ��������ÿ����Ʒ����������
select ��Ʒ����, �������� = SUM(��������) 
from MrOrders 
group by ��Ʒ���� 
order by SUM(��������) desc
--2.��ͳ�����ۼ۸񳬹�3000Ԫ����Ʒ���ƺ������ܼ�
select ��Ʒ����, �����ܼ� = SUM(��������*���ۼ۸�) 
from MrOrders 
group by ��Ʒ���� 
having SUM(��������*���ۼ۸�)>3000 
order by �����ܼ� desc
--3.ͳ�Ƹ����ͻ��ԡ��ɿڿ��֡���ϲ���̶ȣ�ͳ��ÿ�˵Ĺ�����
select ������, ���������� = SUM(��������) 
from MrOrders 
where ��Ʒ����='�ɿڿ���' 
group by ������ 
order by ���������� 
desc

--����װ�� CAST CONVERT ISNULL
select '��ǰʱ��'+GETDATE()
--����һ
select '��ǰʱ��'+CAST(GETDATE() as varchar(20))
--������
select '��ǰʱ��'+ CONVERT(varchar(20),GETDATE(),120)
--������
select 
	ISNULL(CONVERT(varchar(10),tsEnglish),'ȱ��')--�ж��Ƿ�ΪNULL
from tblScore

select CAST(9.85 as int) --��ȥС��

--select * frome class1, class2--�ѿ�����

--���Ͻ����,���ϵ�����Ŀ������Ҫ��ͬ
select tsid, tsname, tsaddress from student
union
select tclassid, tclassname, tclassdesc from TblClass
union
select sid, CONVERT(varchar(5),tsmath),CONVERT(varchar(10),tsenglish) from TblScore
--union, �б���
select '��߳ɼ�' as ����,MAX(tsenglish) as ���� from tblscore
union
select '��ͳɼ�',MIN(tsenglish) from tbScore
union
select '��ͳɼ�',AVG(tsenglish) from tbScore
--union��ȥ���ظ� Ч�ʵͣ�union all����ȥ���ظ� Ч�ʸ�

--����,ֻ�������ݲ�����Լ�������ݱ�δ��
--����һ  ��������+�ṹ
select * into newStudent from student
--������ ֻ���ݽṹ,����������
select * into newStudent from student where 1<>1--Ч�ʵ�
--������ ֻ���ݽṹ
select top 0 * from newStudent from student--Ч�ʸ�
--���ݱ��ѽ�
insert into backupStudent select * from student--backupStudent�������ǰ����

--�ַ�������
--��ѯ�ַ�������
select LEN(className) from class
select LEN('һ����') from class
--��ѯ�ֽ���
select DATALENGTH('�������ֱ�˧��')
select DATALENGTH(classDesc) from class --���ֽڵ�ʱ��Ҫ�ȿ������е���������
--ת��Сд
select LOWER('HELLO')
select UPPER('word')
--ȥ���ո�
select '====='+LTRIM('     �������������Ű�����      ')+'=='
select '====='+RTRIM('     �������������Ű�����      ')+'=='
select '====='+RTRIM(LTRIM('     �������������Ű�����      '))+'=='

--ʱ�亯��
select GETDATE();--��ǰ��������ʱ��
--�ӷ������ã�
select DATEADD(YEAR,5,GETDATE())--����֮��
select DATEADD(MONTH,5,GETDATE())--����֮��
select DATEADD(DAY,5,GETDATE())--����֮��
select DATEADD(HOUR,5,GETDATE())--��Сʱ֮��
select DATEADD(SECOND,5,GETDATE())--����֮��
--��ȡ���꣬���
select DATEDIFF(YEAR,'2010',GETDATE())
--��ȡʱ���ĳ������
select DATEPART(YEAR,HOUR,GETDATE())

--������ݵ�ͬʱ����ȡ�ò�����id
--�����ݿ���@@��ͷ��Ϊȫ�ֱ���
insert into DeskInfo values('1�ò���','pinyin',0,'123')
select @@IDENTITY

insert into DeskInfo(DeskName,DeskNamePinYin,DeskDelFlag,DeskNum)output inserted.DeskId,inserted.DeskName values('�غò���','pinyin',0,'123')

--��������
update ETU35_37 set N_TrippingTime_Tolerance_tmax = (select L_TrippingTime_Tolerance_tmax )from ETU35_37
update ETU35_37 set Ii_Tripping_Tolerance_Imax = (select Ii_Tripping_ETU_Ii)*1.2 from ETU35_37
select * from ETU35_37

update ETU45_47 set L_Tripping_ETU_IR = (select L_Tripping_ETU_IR) from ETU35_37

select * from ETU45_47
update ETU45_47 set G_Tripping_Tolerance_Imax = 360

update ETU45_47 set I_Tripping_Tolerance_Imax = (select I_Tripping_Tolerance_Imin)*1.2 from ETU45_47
update ETU45_47 set N_Tripping_Tolerance_tmin = (select L_Tripping_Tolerance_tmin)from ETU45_47
update ETU45_47 set N_Tripping_Tolerance_tmax = (select L_Tripping_Tolerance_tmax) from ETU45_47

--CASE���
SELECT 
��ѧ�ɼ� = 
CASE
	WHEN TSEnglish>120 THEN 'A'
	WHEN TSEnglish>100 THEN 'B'
	WHEN TSEnglish>80 THEN 'C'
	WHEN TSEnglish>70 THEN 'D'
	WHEN TSEnglish IS NULL THEN 'abpresent'
	ELSE 'E'
END
FROM TbScore

SELECT *,
���� = 
(
	CASE
		WHEN [Level] = 1 THEN 'СϺ��'
		WHEN [Level] = 2 THEN '�ڻ�'
		WHEN [Level] = 3 THEN '����'
	END
)
FROM Genius

----��SQL���ʵ�֣���A�д���B��ʱѡ��A�з���ѡ��B�У���B�д���C��ʱѡ��B�з���ѡ��C�С�
SELECT (CASE WHEN a>b THEN a ELSE b END),(CASE WHEN b>c THEN b ELSE c END)
FROM t

-----------�����ķָ���-----------
SELECT 
[����],
����=
(
	CASE
		WHEN[���]>0 THEN [���] ELSE 0
	END
)
,
֧��=
(
	CASE
		WHEN[���]<0 THEN ABS([���]) ELSE 0
	END
)
FROM Sale


--�Ӳ�ѯ:���������ͨ��һ����������������Ĳ�ѯ��䶼��Ϊ�Ӳ�ѯ�����п���ʹ�ñ�ĵط�������������ʹ���Ӳ�ѯ

SELECT * FROM (SELECT * FROM [TABLE] WHERE '����') AS [Alias]
-----as�����ã�һ���������������߱�����������-����ѯ�������������
SELECT * FROM (SELECT TsEnglish FROM TbScore) as t WHERE TSEnglish >90

---1����ѯ���༶������24����������Ӳ�ѯ��
SELECT * FROM (SELECT * FROM Student WHERE TSGender = 1) as stu WHERE TSAge>24

---2����ѯ�����еĺ���һ�ںͺ�����ڵ�ѧ�����Ӳ�ѯ��
SELECT * FROM Student WHERE TClassId in
(SELECT tclassid FROM TblClass where TClassName = '����һ��' or TClassName  = '�������')

---3����ѯ��������������ͬѧ������,��ѧƽ���ɼ�(�Ӳ�ѯ)
SELECT
������ = (SELECT COUNT(*) FROM Student),
��ͬѧ������ = (SELECT COUNT(*) FROM Student WHERE TSGender = 1),
��ѧƽ���ɼ� = (SELECT AVG(TSMath) FROM TbScore)

--��ֵ�Ӳ�ѯ�����ص��ҽ���һ��һ�е�����,������=��<>��һԪ�Ƚ������
--�������������Ŷ���������ôin ���� exists�ؼ���

--DELETE FROM Student WHERE TSID in
--( SELECT TSId FROM Student WHERE TSName = '����' OR TSName = '�ŷ�' OR TSName = '����' )


----��ҳ��ÿҳ�������ݣ���ѯ��4ҳ��

SELECT TOP 5 * FROM CustomerID WHERE NOT IN
(SELECT TOP (5*4) FROM CustomerID ORDER BY CustomerID)
ORDER BY CustomerID

--ÿҳ3�����ݣ���ѯ3ҳ
SELECT TOP 3 * FROM Student WHERE TSID NOT IN
(SELECT TOP(2*3) TSID FROM Student)

--OVER������һ�н�������ROW_NUMBER���
SELECT TSMath,����=ROW_NUMBER()OVER(ORDER BY TSMath desc) from TbScore
--��������RANK,�ظ���������ͬ
SELECT TSMath,����=RANK()OVER(ORDER BY TSMath desc)from TbScore
SELECT *,��ѧ��������=RANK()OVER(ORDER BY TSMath DESC) FROM TbScore
SELECT *,��ѧ��������=RANK()OVER(ORDER BY TSMath DESC) FROM TbScore ORDER BY TSId

---partition����ͬ��Ʒ����������
SELECT ID, ��Ʒ����,�к�=ROW_NUMBER()OVER(PARTITION BY ��Ʒ���� ORDER BY id ASC) FROM MyOrders

---����Ų�ѯ��ÿҳ��ʾ3�����ݣ���ʾ����ҳ
SELECT * FROM 
(SELECT ���=ROW_NUMBER()OVER(ORDER BY TSMath DESC),* FROM TbScore) AS newStu
WHERE newStu.��� BETWEEN (5-1)*3+1 AND 3*5