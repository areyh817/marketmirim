/* MySQL 테이블 구조 */
create table product(
    -> id int(20),
    -> foodname varchar(100),
    -> cnt int(50),
    -> money int(100)
    -> );


create table user(
    -> id int(20) not null primary key,
    -> pw varchar(30),
    -> name varchar(30)
    -> );