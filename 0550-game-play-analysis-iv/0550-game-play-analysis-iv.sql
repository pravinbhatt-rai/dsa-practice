# Write your MySQL query statement below

SELECT
    ROUND(
        AVG(
            IF(
                event_date = DATE_ADD(first_login.first_date, INTERVAL 1 DAY),
                1,
                0
            )
        ),
        2
    ) AS fraction
FROM (
    SELECT player_id,
           MIN(event_date) AS first_date
    FROM Activity
    GROUP BY player_id
) AS first_login
LEFT JOIN Activity
ON Activity.player_id = first_login.player_id
AND Activity.event_date = DATE_ADD(first_login.first_date, INTERVAL 1 DAY);