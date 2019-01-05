-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL,ALLOW_INVALID_DATES';

-- -----------------------------------------------------
-- Schema lab2-17
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema lab2-17
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `lab2-17` DEFAULT CHARACTER SET utf8 ;
-- -----------------------------------------------------
-- Schema lab2-17
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema lab2-17
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `lab2-17` DEFAULT CHARACTER SET utf8 ;
USE `lab2-17` ;

-- -----------------------------------------------------
-- Table `lab2-17`.`departments`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `lab2-17`.`departments` (
  `department_id` INT NOT NULL,
  `empl_amount` INT NOT NULL,
  `name` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`department_id`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `lab2-17`.`employees`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `lab2-17`.`employees` (
  `employee_id` INT NOT NULL,
  `name` VARCHAR(45) NOT NULL,
  `surname` VARCHAR(45) NOT NULL,
  `department_id` INT NOT NULL,
  PRIMARY KEY (`employee_id`, `department_id`),
  INDEX `employee_idx` (`department_id` ASC),
  CONSTRAINT `employee`
    FOREIGN KEY (`department_id`)
    REFERENCES `lab2-17`.`departments` (`department_id`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `lab217`.`consumptions`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `lab2-17`.`consumptions` (
  `consumption_id` INT NOT NULL,
  `name` VARCHAR(45) NOT NULL,
  `description` VARCHAR(100) NULL,
  `max_amount` INT NOT NULL,
  `department_id` INT NOT NULL,
  PRIMARY KEY (`consumption_id`),
  INDEX `consumption_idx` (`department_id` ASC),
  CONSTRAINT `consumption`
    FOREIGN KEY (`department_id`)
    REFERENCES `lab2-17`.`departments` (`department_id`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;

USE `lab2-17` ;

-- -----------------------------------------------------
-- Table `lab2-17`.`consumptions`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `lab2-17`.`consumptions` (
  `consumption_id` INT(11) NOT NULL,
  `name` VARCHAR(45) NOT NULL,
  `description` VARCHAR(100) NULL DEFAULT NULL,
  `max_amount` INT(11) NOT NULL,
  `department_id` INT(11) NOT NULL,
  PRIMARY KEY (`consumption_id`),
  INDEX `consumption_idx` (`department_id` ASC),
  CONSTRAINT `consumption`
    FOREIGN KEY (`department_id`)
    REFERENCES `lab2-17`.`departments` (`department_id`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `lab2-17`.`departments`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `lab2-17`.`departments` (
  `department_id` INT(11) NOT NULL,
  `empl_amount` INT(11) NOT NULL,
  `name` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`department_id`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `lab2-17`.`employees`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `lab2-17`.`employees` (
  `employee_id` INT(11) NOT NULL,
  `name` VARCHAR(45) NOT NULL,
  `surname` VARCHAR(45) NOT NULL,
  `department_id` INT(11) NOT NULL,
  PRIMARY KEY (`employee_id`, `department_id`),
  INDEX `employee_idx` (`department_id` ASC),
  CONSTRAINT `employee`
    FOREIGN KEY (`department_id`)
    REFERENCES `lab2-17`.`departments` (`department_id`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
