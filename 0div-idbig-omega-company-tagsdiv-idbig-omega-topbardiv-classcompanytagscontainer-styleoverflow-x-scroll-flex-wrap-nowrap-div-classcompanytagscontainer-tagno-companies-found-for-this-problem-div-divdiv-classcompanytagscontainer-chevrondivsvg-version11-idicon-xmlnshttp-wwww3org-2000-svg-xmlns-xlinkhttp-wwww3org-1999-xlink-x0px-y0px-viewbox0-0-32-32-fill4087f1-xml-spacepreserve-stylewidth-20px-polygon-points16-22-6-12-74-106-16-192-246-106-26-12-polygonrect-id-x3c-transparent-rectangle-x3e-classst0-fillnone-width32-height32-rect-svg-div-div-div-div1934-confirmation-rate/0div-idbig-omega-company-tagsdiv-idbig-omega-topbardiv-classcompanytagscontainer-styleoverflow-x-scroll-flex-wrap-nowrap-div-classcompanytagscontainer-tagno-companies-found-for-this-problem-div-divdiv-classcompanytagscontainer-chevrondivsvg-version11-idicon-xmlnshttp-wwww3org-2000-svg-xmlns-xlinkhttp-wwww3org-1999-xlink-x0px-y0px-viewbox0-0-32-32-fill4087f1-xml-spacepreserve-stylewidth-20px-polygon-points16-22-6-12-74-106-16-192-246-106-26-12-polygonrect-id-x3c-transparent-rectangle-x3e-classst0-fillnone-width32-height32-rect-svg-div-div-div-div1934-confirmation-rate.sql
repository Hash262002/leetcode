select s.user_id , ifnull(round(c.total_confirmed/c.total_actions,2),0) as confirmation_rate from Signups s left join (select user_id ,sum(if(action="confirmed",1,0)) as total_confirmed, count(user_id) as total_actions from Confirmations group by user_id) c on s.user_id=c.user_id