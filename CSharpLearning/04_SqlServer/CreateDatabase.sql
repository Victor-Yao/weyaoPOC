--1.���봴�����ݿ�
CREATE DATABASE MyDBDemo
ON PRIMARY(
	--�����ļ�����
	NAME='MyDBDemo',
	--·��
	FILENAME='c:\Program Files\Microsoft SQL Server\MSSQL11.SQLEXPRESS\MSSQL\DATA\MyDBDemo.mdf',
	--��ʼ��С
	SIZE=5MB,
	--����
	FILEGROWTH=1MB
)
LOG ON(
	--��־�ļ�����
	NAME='MyDBDemo_log',
	--·��
	FILENAME='c:\Program Files\Microsoft SQL Server\MSSQL11.SQLEXPRESS\MSSQL\DATA\MyDBDemo_log.ldf',
	--��ʼ��С
	SIZE=3MB,
	--����
	FILEGROWTH=10%
)


--2.���봴����
Create table class(
	--identity(1,1)��1��ʼ��ÿ������1
	classId int identity(1,1) primary key,
	className nvarchar(10) not null,
	classDesc nvarchar(50)
)
create table Employees(
	EmpId int identity(1,1),
	EmpName varchar(50),
	EmpGender char(2),
	EmpAge int,
	EmpEmail varchar(100),
	EmpAddress varchar(500)
)
create table Department(
	DepId int identity(1,1) primary key,
	DepName varchar(50) unique not null	
)

--����������Ϣ�������ֶΣ���������ţ���Ϣ����ע����ʾ��ʱ�䣩
Create table Desk
(
	DeskId int identity(1,1) primary key,
	DeskNum nvarchar(10),
	DeskInfo nvarchar(10),
	DeskRemark nvarchar(20),
	Flag int,
	DeskSetTime Datetime
)


--3.������������
--����1��������Ӱ�������
--Insert into ����(��1,��2) values(ֵ1,ֵ2)������ֱ�Ӱ�'��'�Ϲ���
insert into class(className,classDesc) values('���ж���','����һ����')
--����2��
--insert into ���� values(ֵ)
insert into class values('����һ��','������')
--����3��һ�β����������
insert into class values('����һ��','������')
insert into class values('��������','���Ǻ���')
--����4���ͷ�������ͬ��һ�β����������
insert into class(className,classDesc)
select N'����1-3','��������' union --N���ڽ��������������
select '����4-6','�е�����' union
select '����7��','��������'


--4.�޸����ݣ�������Ӱ�������
--update ���� set ��1=ֵ1,��2=ֵ2
update class set classDesc = '��������' --���ֶ����������ж�����
update class set classDesc = '�Ƚ�����' where classId = 1 or classId = 6 --ֻ�޸������ж���������
update class set classDesc = '�Ƚ�����', className='��һ����' where classId = 1
--������>25��ѧ�����䶼��1
update student set TSAge=TSAge+1 where TSAge>25
--������ѧ���ĳɼ�+5�֣����������ֵ����������100��
update TblScore set tEnglish=100 where tEnglish+5>100
update TblScore set tEnglish=tEnglish+5 where tEnglish+5<100


--5.�л����ݿ�
use TestDB
insert into class values('���ж���','����һ����')
select * from class


--6.ɾ����������Ӱ�������
--����1��ɾ�����е�ָ�����ݣ�����������ȫ��ɾ���������ڣ�ID��ɾ��ǰ��ID��ʼ+1
delete from class
delete from class where classId = 10
--����2��ɾ�����е�ȫ������,���ڣ�ID��1��ʼ
truncate table class
--����3��ɾ�������ײ�ʹ��
drop table Desk


--7.������Ʊ����ֶ�������ɾ�������Լ��
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


--8.��ѯ
select * from class
Select EmpName, EmpAge from Employees
--����1
Select EmPname as '����', EmpAge as '����' from Employees
--����2
Select EmPname as ����, EmpAge as ���� from Employees
--����3
Select ����=EmpName, ����=EmpAge from Employees
--��������
Select EmPname as '����', EmpAge as '����' from Employees where EmpGender = 1

--select��ʾ�ڡ������
Select 100+1
Select GETDATE()
--print��ʾ�ڡ���Ϣ��
print 100+90
print '��ǰʱ��'+getdate() --���ڡ��ַ������͡�ʱ�䡱��ʽװ��������


--9.��ѯǰn�� + ����
--��ѯ�������ݵ�ǰ10������
Select top 10* from Employees
--��ѯ������С��5��ѧ������Ϣ
Select top 5* from Employees order by EmpAge --Ĭ������������asce
--�Ӵ�С���򣬲�ѯ�����������İٷ�֮10��ѧ����Ϣ
Select top 10 percent * from Employees order by EmpAge desc --��������
--��Ӣ��ɼ����򣬲��е�����ѧ�ɼ�����������
Select * from tblScore where order by tsEnglish desc, order by tsMath desc
Select *, �ܳɼ� = (tsenglish + tsmath) from tblScore where order by (tsEnglish +tsMath) desc
--ȥ���ظ� 
--distinct�ڲ�ѯ�����ȥ���ظ���������������ĳһ��
Select distinct EmpName from Employees


--10.�ۺϺ���:MAX, MIN, AVG, SUM, COUNT, 
--null������ۺϺ��������㣬�������������������
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


--11.С�����ܽ᣺
---a.����*��������,�����еĲ�ѯ�ٶ��б�*��
select * from table
select ������ from table 
---b.���У����԰��ؼ��ֻ��У���Ӱ�����㡣�����д
select 
MAX(tsenglish) as '���ֵ', 
AVG(tsenglish) as 'ƽ��ֵ', 
SUM(tsenglish) as '�ܺ�' 
from tblScore
---c.null�Ƿ������*������,COUNT(*)����null,COUNT(����)������
select  COUNT(*) from tblScore
select COUNT(tsEnglish) from tblScore


--12.�������Ĳ�ѯ
---a.between...and���������ѯ���������ޣ�
select * from Employees where EmpAge>20 and EmpAge<30 and EmpGender = 1
select * from Employees where EmpGender = 1 and EmpAge Between 20 and 30 --between...and�����Ż�������Ч
---b.in��������������ѯ
select * from Employees where EmpId = 1 or EmpId = 2 or EmpId = 3
select * from Employees where EmpId in (1,2,3)--�����ֱ��


--13.ģ����ѯ like��
---ͨ���%, _, []�����ڹؼ�������, ^(ֻ��MSSQLSERVER֧�֣�����DBMS��not like)
--�����������ŵ���������
select * from Employees where EmpName like '��%'
--�ź����һ����
select * from Employees where EmpName like '��_'
--�ź����������
select * from Employees where EmpName like '��__'
select * from Employees where EmpName like '��%' and LEN(EmpName) = 3
--��������ĸ������
select * from Employees where EmpName like '��[a-z]%'
--����������ŵģ���һ������
select * from Employees where EmpName like '%��%'
--���ŵ�����������ٷֺŵ�
select * from Employees where EmpName like '��[%]%' --�����д���%��
select * from Employees where EmpName like '��[_]%' --�����д���-��
--���ŵ������������������
select * from Employees where EmpName like '��[0-9]_' --���ſ�ͷ�������֣������ֵ�����
select * from Employees where EmpName like '��[^0-9]_' --...���������֣�...


--14.��ֵ����,null���ǿգ�����δ֪���ݣ��ж��ǲ���null
select * from Employees where EmpAge is null
select * from Employees where EmpAge is not null


--15.���飬group by
--��ѯÿ���༶��������
select tclassid as '�༶', COUNT(*) as '����' from student group by tclassid
--��ѯÿ���༶����ͬѧ������
select tclassid as '�༶', COUNT(*) as '����' from student where Gender = 1 group by tclassid
--����ɸѡ��having;����ǰ��where
select tclassid as '�༶', COUNT(*) as '����' from student group by tclassid
having count(*)>3


--###С��ϰ###
---a.��������Ʒ��������ÿ����Ʒ����������
select ��Ʒ����, �������� = SUM(��������) 
from MrOrders 
group by ��Ʒ���� 
order by SUM(��������) desc
---b.��ͳ�����ۼ۸񳬹�3000Ԫ����Ʒ���ƺ������ܼ�
select ��Ʒ����, �����ܼ� = SUM(��������*���ۼ۸�) 
from MrOrders 
group by ��Ʒ���� 
having SUM(��������*���ۼ۸�)>3000 
order by �����ܼ� desc
---c.ͳ�Ƹ����ͻ��ԡ��ɿڿ��֡���ϲ���̶ȣ�ͳ��ÿ�˵Ĺ�����
select ������, ���������� = SUM(��������) 
from MrOrders 
where ��Ʒ����='�ɿڿ���' 
group by ������ 
order by ���������� 
desc


--16.����װ��, CAST CONVERT ISNULL
--select '��ǰʱ��'+GETDATE() --���Ͳ����ݣ���Ҫת��
---a.CAST
select '��ǰʱ��'+CAST(GETDATE() as varchar(20))
---b.CONVERT
select '��ǰʱ��'+ CONVERT(varchar(20),GETDATE())
select '��ǰʱ��'+ CONVERT(varchar(20),GETDATE(),120) --120��ָ��ת����ʱ���ʽ
---c.�ж�ת�������Ƿ�Ϊ��
select 
	ISNULL(CONVERT(varchar(10),tsEnglish),'ȱ��')--�ж��Ƿ�ΪNULL�����������'ȱ��'�滻
from tblScore
---d.��ȥС��
select CAST(9.85 as int)


--select * frome class1, class2--�ѿ�����
--17.���Ͻ����, union
---a.Ҫ������Ŀ��ͬ��������ͬ
select tsid, tsname, tsaddress from student
union
select tclassid, tclassname, tclassdesc from TblClass
union
select sid, CONVERT(varchar(5),tsmath),CONVERT(varchar(10),tsenglish) from TblScore
---b.union, �б���
select '��߳ɼ�' as ����,MAX(tsenglish) as ���� from tblscore
union
select '��ͳɼ�',MIN(tsenglish) from tbScore
union
select '��ͳɼ�',AVG(tsenglish) from tbScore
---c.union all����ȥ���ظ� Ч�ʸߣ�union��ȥ���ظ� Ч�ʵ�
select tsName from TblStudent
union all
select tClassName from TblClass


--18.��������һ�����е����ݻ�ṹ���Ƶ���һ�����У�������Լ��
---a.���ƽṹ������
select * into newStudent from student
---b.ֻ���ƽṹ
select * into newStudent from student where 1<>1 --Ч�ʵ�
select top 0 * from newStudent from student --Ч�ʸ�
---c.backupStudent�������ǰ����
insert into backupStudent select * from student


--19.�ַ�������
---a.��ѯ�ַ�������
select LEN(className) from class
select LEN('һ����') from class
---b.��ѯ�ֽ���
select DATALENGTH('�������ֱ�˧��')
select DATALENGTH(classDesc) from class --���ֽڵ�ʱ��Ҫ�ȿ������е���������
---c.ת��Сд
select LOWER('HELLO')
select UPPER('word')
---d.ȥ���ո�
select '====='+LTRIM('     �������������Ű�����      ')+'=='
select '====='+RTRIM('     �������������Ű�����      ')+'=='
select '====='+RTRIM(LTRIM('     �������������Ű�����      '))+'=='

--20.ʱ�亯��
select GETDATE();--��ȡ��ǰ���ݿ����ڷ�������ʱ��
---a.�ӷ�
select DATEADD(YEAR,5,GETDATE())--����֮��
select DATEADD(MONTH,5,GETDATE())--����֮��
select DATEADD(DAY,5,GETDATE())--����֮��
select DATEADD(HOUR,5,GETDATE())--��Сʱ֮��
select DATEADD(SECOND,5,GETDATE())--����֮��
---b.��ȡ���꣬���
select DATEDIFF(YEAR,'2010',GETDATE())
--��ȡʱ���ĳ������
select DATEPART(YEAR,HOUR,GETDATE())

--������ݵ�ͬʱ����ȡ�ò�����id
--�����ݿ���@@��ͷ��Ϊȫ�ֱ���
insert into DeskInfo values('1�ò���','pinyin',0,'123')
select @@IDENTITY

insert into DeskInfo(DeskName,DeskNamePinYin,DeskDelFlag,DeskNum)output inserted.DeskId,inserted.DeskName values('�غò���','pinyin',0,'123')


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