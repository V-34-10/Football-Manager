-- MySQL dump 10.13  Distrib 8.0.23, for Win64 (x86_64)
--
-- Host: localhost    Database: football_manager
-- ------------------------------------------------------
-- Server version	8.0.23

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `klub`
--

DROP TABLE IF EXISTS `klub`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `klub` (
  `Id_klub` int NOT NULL AUTO_INCREMENT,
  `Name` varchar(25) NOT NULL,
  `Pib_trener` varchar(45) NOT NULL,
  `Liga` varchar(45) NOT NULL,
  `Image` varchar(45) NOT NULL,
  PRIMARY KEY (`Id_klub`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `klub`
--

LOCK TABLES `klub` WRITE;
/*!40000 ALTER TABLE `klub` DISABLE KEYS */;
INSERT INTO `klub` VALUES (1,'ФК Динамо','Мірча Луческу','Українська ліга','Dinamo-1.jpg'),(2,'ФК Шахтар','Де Дзерби, Роберто','Українська ліга','FC_Shakhtar-1.jpg'),(3,'ФК Десна','Рябоконь Олександр','Українська ліга','Desna-1.jpg'),(4,'ФК Верес','Юрій Вірт','Українська ліга','Veres-1.jpg'),(5,'ФК Карпати','Андрій Тлумак','Українська ліга','Karpaty-1.jpg');
/*!40000 ALTER TABLE `klub` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `list_player`
--

DROP TABLE IF EXISTS `list_player`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `list_player` (
  `id_player` int NOT NULL,
  `id_plan` int NOT NULL,
  PRIMARY KEY (`id_player`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `list_player`
--

LOCK TABLES `list_player` WRITE;
/*!40000 ALTER TABLE `list_player` DISABLE KEYS */;
INSERT INTO `list_player` VALUES (1,1),(2,1),(3,1),(4,3),(5,3),(6,3),(7,2),(8,2),(9,2),(10,4),(11,4),(12,4),(13,3),(14,3),(15,3),(16,3),(17,3),(18,3),(19,3),(20,3),(21,1),(22,1),(23,1),(24,1),(25,1);
/*!40000 ALTER TABLE `list_player` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `match`
--

DROP TABLE IF EXISTS `match`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `match` (
  `id_match` int NOT NULL AUTO_INCREMENT,
  `id_klub1` int NOT NULL,
  `klub2` varchar(25) NOT NULL,
  `date_match` date NOT NULL,
  `id_plan` int NOT NULL,
  `kol_ball` int NOT NULL,
  `kol_gears` int NOT NULL,
  `result` varchar(3) NOT NULL,
  `sezon` varchar(15) NOT NULL,
  `image` varchar(45) NOT NULL,
  PRIMARY KEY (`id_match`)
) ENGINE=InnoDB AUTO_INCREMENT=17 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `match`
--

LOCK TABLES `match` WRITE;
/*!40000 ALTER TABLE `match` DISABLE KEYS */;
INSERT INTO `match` VALUES (1,1,'ФК Шахтар','2021-10-02',1,2,2,'0:2','2021-2022','Dinamo-Shahtar.jpg'),(2,2,'ФК Верес','2021-09-24',2,6,3,'6:0','2021-2022','Veres-Shahtar.jpg'),(3,4,'ФК Десна','2021-12-05',3,2,1,'1:1','2021-2022','Desna-Veres.jpg'),(4,3,'ФК Динамо','2021-11-21',4,4,3,'0:4','2021-2022','Dinamo-Desna.jpg'),(5,2,'ФК Десна','2021-10-29',1,4,2,'4:0','2021-2022','Desna-Shahtar.jpg'),(7,1,'ФК Десна','2021-08-21',1,4,4,'4:0','2021-2022','Dinamo-Desna.jpg'),(8,3,'ФК Верес','2021-08-29',2,4,1,'0:4','2021-2022','Desna-Veres.jpg'),(9,2,'ФК Десна','2021-10-30',3,5,4,'4:1','2021-2022','Desna-Shahtar.jpg'),(10,2,'ФК Динамо','2021-09-21',3,3,1,'3:0','2021-2022','Dinamo-Shahtar.jpg'),(16,2,'ФК Верес','2022-04-15',5,7,3,'4:3','2021-2022','error1.jpg');
/*!40000 ALTER TABLE `match` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `plan`
--

DROP TABLE IF EXISTS `plan`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `plan` (
  `id_plan` int NOT NULL AUTO_INCREMENT,
  `name_plan` varchar(15) NOT NULL,
  PRIMARY KEY (`id_plan`)
) ENGINE=InnoDB AUTO_INCREMENT=40 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `plan`
--

LOCK TABLES `plan` WRITE;
/*!40000 ALTER TABLE `plan` DISABLE KEYS */;
INSERT INTO `plan` VALUES (1,'4-3-3'),(2,'4-1-2-1-2'),(3,'4-3-2-1'),(4,'4-4-2'),(5,'4-5-1');
/*!40000 ALTER TABLE `plan` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `player`
--

DROP TABLE IF EXISTS `player`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `player` (
  `id_player` int NOT NULL AUTO_INCREMENT,
  `Id_klub` int NOT NULL,
  `pib` varchar(45) NOT NULL,
  `date` date NOT NULL,
  `position` varchar(5) NOT NULL,
  `number` varchar(2) NOT NULL,
  `image` varchar(45) NOT NULL,
  PRIMARY KEY (`id_player`)
) ENGINE=InnoDB AUTO_INCREMENT=26 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `player`
--

LOCK TABLES `player` WRITE;
/*!40000 ALTER TABLE `player` DISABLE KEYS */;
INSERT INTO `player` VALUES (1,1,'Микола Шапаренко','1998-10-04','АПЗ','10','Shaparenko.jpg'),(2,1,'Георгій Бущан','1994-05-31','ВР','1','Bushchan.jpg'),(3,1,'Сергій Сидорчук','1991-05-02','ЦПЗ','5','Sydorchuk.jpg'),(4,2,'Марлос Ромеро','1988-06-07','АПЗ','11','Marlos.jpg'),(5,2,'Євген Коноплянка','1989-09-29','ЛПЗ','70','Konoplyanka.jpg'),(6,2,'Андрій П\'ятов','1984-06-28','ВР','30','Pyatov.jpg'),(7,3,'Олексій Ковтун','1995-02-05','ЦЗ','6','Kovtun.jpg'),(8,3,'Дмитро Сидоренко','2002-11-12','ВР','1','Sudorenko.jpg'),(9,3,'Денис Безбородько','1994-05-31','НП','20','Bezborodyko.jpg'),(10,4,'Роберт Гегедош','1993-05-02','НП','88','Gegedosh.jpg'),(11,4,'Віталій Дахновський','1999-02-10','ПЗ','11','Dahnovskiy.jpg'),(12,4,'Богдан Когут','1987-10-10','ВР','47','Kogut.jpg'),(13,2,'Крістіан Бако','2003-01-07','НП','0','not_image.jpg'),(14,2,'Гонсалвес Ісмаїлі','1990-01-11','ЦЗ','31','Ismaili.jpg'),(15,2,'Майкон','1997-07-15','АПЗ','7','Maikon.jpg'),(16,2,'Дентіньо','1989-01-19','АПЗ','9','Dentinio.jpg'),(17,2,'Степаненко Тарас','1989-08-08','ЦПЗ','6','Stepanenko.jpg'),(18,2,'Алан Патрік','1991-05-13','ППЗ','21','Patrik.jpg'),(19,2,'Мораєс','1987-04-04','НП','10','Moraes.jpg'),(20,2,'Траоре','2001-01-12','НП','23','Traore.jpg'),(21,1,'Бурда Микита','1995-03-21','ЦЗ','6','Burda.jpg'),(22,1,'Тимчик Олександр','1997-01-20','ЛЗ','24','Timchuk.jpg'),(23,1,'Гармаш Денис','1990-04-19','ППЗ','19','Garmash.jpg'),(24,1,'Циганков Віктор','1997-11-15','ЛПЗ','15','Cugankov.jpg'),(25,1,'Бесєдін Артем','1996-03-31','НП','41','Besedin.jpg');
/*!40000 ALTER TABLE `player` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `sezon`
--

DROP TABLE IF EXISTS `sezon`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `sezon` (
  `name` varchar(15) NOT NULL,
  `date1` date NOT NULL,
  `date2` date NOT NULL,
  PRIMARY KEY (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `sezon`
--

LOCK TABLES `sezon` WRITE;
/*!40000 ALTER TABLE `sezon` DISABLE KEYS */;
INSERT INTO `sezon` VALUES ('2019-2020','2019-01-01','2020-12-31'),('2020-2021','2020-01-01','2021-12-31'),('2021-2022','2021-01-01','2022-12-31');
/*!40000 ALTER TABLE `sezon` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `transfer`
--

DROP TABLE IF EXISTS `transfer`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `transfer` (
  `id_transfer` int NOT NULL AUTO_INCREMENT,
  `term` int NOT NULL,
  `date_1` date NOT NULL,
  `date_2` date NOT NULL,
  `price` int NOT NULL,
  `id_player` int NOT NULL,
  PRIMARY KEY (`id_transfer`)
) ENGINE=InnoDB AUTO_INCREMENT=13 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `transfer`
--

LOCK TABLES `transfer` WRITE;
/*!40000 ALTER TABLE `transfer` DISABLE KEYS */;
INSERT INTO `transfer` VALUES (1,24,'2021-01-01','2023-01-01',25,1),(2,36,'2021-01-01','2024-01-01',30,2),(3,48,'2021-01-01','2025-01-01',35,4),(4,24,'2019-01-01','2021-01-01',25,25),(5,36,'2020-01-01','2023-01-01',18,22),(6,60,'2020-01-01','2025-01-01',40,19),(7,12,'2020-01-01','2021-01-01',21,13),(8,24,'2020-01-01','2022-01-01',29,5),(9,36,'2019-01-01','2022-01-01',35,6),(10,12,'2020-01-01','2021-01-01',15,9),(12,24,'2021-10-28','2023-10-28',22,24);
/*!40000 ALTER TABLE `transfer` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2021-11-08 19:02:56
