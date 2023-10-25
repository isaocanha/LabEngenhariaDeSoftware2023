-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Tempo de geração: 25/10/2023 às 14:52
-- Versão do servidor: 10.4.28-MariaDB
-- Versão do PHP: 8.2.4

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Banco de dados: `BancoGeral`
--

-- --------------------------------------------------------

--
-- Estrutura para tabela `mercados`
--

CREATE TABLE `mercados` (
  `id` int(11) NOT NULL,
  `mercados` varchar(14) NOT NULL,
  `Localização` varchar(14) NOT NULL,
  `Endereço` varchar(14) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Despejando dados para a tabela `mercados`
--

INSERT INTO `mercados` (`id`, `mercados`, `Localização`, `Endereço`) VALUES
(1, 'MercadoA', 'LocalizaçãoA', 'EndereçoA'),
(2, 'MercadoB', 'LocalizaçãoB', 'EndereçoB'),
(3, 'MercadoC', 'LocalizaçãoC', 'EndereçoC'),
(4, 'MercadoD', 'LocalizaçãoD', 'EndereçoD');

--
-- Índices para tabelas despejadas
--

--
-- Índices de tabela `mercados`
--
ALTER TABLE `mercados`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `Endereço` (`Endereço`);

--
-- AUTO_INCREMENT para tabelas despejadas
--

--
-- AUTO_INCREMENT de tabela `mercados`
--
ALTER TABLE `mercados`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
