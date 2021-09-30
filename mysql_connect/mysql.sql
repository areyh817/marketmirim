create table product(
    -> product_id int(10) not null primary key,
    -> product_name varchar(20),
    -> product_price int(10),
    -> product_cnt int(30)
    -> );


create table user(
    -> id int(20) not null primary key,
    -> pw varchar(30),
    -> name varchar(30)
    -> );