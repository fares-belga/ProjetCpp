#include "admins.h"
#include <QSqlQuery>
admins::admins()
{
username="";
pass="";
type="";
action="";
}
admins::admins(QString u ,QString p,QString t,QString a)
{
username=u;
pass=p;
type=t;
action=a;
}
QString admins::getid(){
    QSqlQuery qry;
    int action=1;
    QString res1,res=QString::number(action);

    qry.prepare("select * from admin where action='"+res+"' " );
    if(qry.exec())
    {
        while(qry.next())
        {
            res1=qry.value(0).toString();

        }
    }


    return res1;
}
int admins::role(){
                  QString res1,r=getid();
                  QSqlQuery qry;
                  qry.prepare("select * from admin where username='"+r+"' " );
                  if(qry.exec())
                  {
                      while(qry.next())
                      {
                          res1=qry.value(2).toString();

                      }
                  }
if(res1=="admin"){
return 0;
}
if(res1=="client"){
    return 1;
}
if(res1=="Agent 2"){
    return 2;
}
if(res1=="Agent 3"){
    return 3;
}
if(res1=="Agent 4"){
    return 4;
}
if(res1=="Agent 5"){
    return 5;

}
else
    return -1;
}
