-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL,ALLOW_INVALID_DATES';

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------
-- -----------------------------------------------------
-- Schema lab3
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema lab3
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `lab3` DEFAULT CHARACTER SET utf8 ;
USE `lab3` ;

-- -----------------------------------------------------
-- Table `lab3`.`departments`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `lab3`.`departments` (
  `department_id` INT(11) NOT NULL AUTO_INCREMENT,
  `empl_amount` INT(11) NOT NULL,
  `name` VARCHAR(45) NOT NULL,
  `max_amount` INT(11) NOT NULL,
  PRIMARY KEY (`department_id`))
ENGINE = InnoDB
AUTO_INCREMENT = 6
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `lab3`.`consumptions`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `lab3`.`consumptions` (
  `consumption_id` INT(11) NOT NULL AUTO_INCREMENT,
  `name` VARCHAR(45) NOT NULL,
  `description` VARCHAR(100) NULL DEFAULT NULL,
  `department_id` INT(11) NOT NULL,
  PRIMARY KEY (`consumption_id`),
  INDEX `consumption_idx` (`department_id` ASC),
  CONSTRAINT `consumption`
    FOREIGN KEY (`department_id`)
    REFERENCES `lab3`.`departments` (`department_id`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB
AUTO_INCREMENT = 6
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `lab3`.`employees`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `lab3`.`employees` (
  `employee_id` INT(11) NOT NULL AUTO_INCREMENT,
  `name` VARCHAR(45) NOT NULL,
  `department_id` INT(11) NOT NULL,
  `age` INT(11) NULL DEFAULT NULL,
  `salary` INT(11) NULL DEFAULT NULL,
  PRIMARY KEY (`employee_id`, `department_id`),
  INDEX `employee_idx` (`department_id` ASC),
  CONSTRAINT `employee`
    FOREIGN KEY (`department_id`)
    REFERENCES `lab3`.`departments` (`department_id`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB
AUTO_INCREMENT = 12
DEFAULT CHARACTER SET = utf8;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
