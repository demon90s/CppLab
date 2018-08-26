DROP TABLE IF EXISTS test;

CREATE TABLE `test` (
  `inc_id` int(11) NOT NULL AUTO_INCREMENT,
  `number_char` tinyint(4) NOT NULL,
  `number_int` int(11) NOT NULL,
  `number_ll` bigint(20) NOT NULL,
  `name` varbinary(32) NOT NULL DEFAULT '',
  PRIMARY KEY (`inc_id`)
) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;


