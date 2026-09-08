SELECT 
    ROUND(
        COUNT(*) * 100.0 / (SELECT COUNT(DISTINCT customer_id) FROM delivery),
        2
    ) AS immediate_percentage
FROM (
    SELECT customer_id
    FROM delivery
    GROUP BY customer_id
    HAVING MIN(order_date) = MIN(customer_pref_delivery_date)
) a;