-- auto-generated definition
create table xf_user
(
    id         bigint unsigned                            not null comment '用户主键'
        primary key,
    number     varchar(10)                                not null comment '员工编号',
    name       varchar(5)                                 not null comment '姓名',
    sex        tinyint unsigned default '0'               not null comment '性别(0男，1女，2不愿透露[非二者])',
    department varchar(20)      default '未归类'          not null comment '部门',
    money      int                                        not null comment '钱',
    level      varchar(20)                                not null comment '级别',
    posts      varchar(10)                                not null comment '职位',
    created_at timestamp        default CURRENT_TIMESTAMP not null comment '创建时间',
    updated_at timestamp                                  null comment '修改时间',
    constraint xf_user_number_uindex
        unique (number)
)
    comment '用户表';

