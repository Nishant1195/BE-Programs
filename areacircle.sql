DELIMITER $$

CREATE PROCEDURE circle_area()
BEGIN
    DECLARE radius1 INT DEFAULT 5;
    DECLARE radius2 INT DEFAULT 9;
    DECLARE pi DECIMAL(3,2) DEFAULT 3.14;
    DECLARE area DECIMAL(6,2);


    WHILE radius1 <= radius2 DO
        SET area = pi * radius1 * radius1;
        INSERT INTO areatable (radius, area) VALUES (radius1, area);
        SET radius1 = radius1 + 1;
    END WHILE;

    -- Select all rows after insertion
    SELECT * FROM areatable;
END $$

DELIMITER ;

CALL circle_area();

//1 2 3
