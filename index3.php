<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $servername = "localhost";
    $username = "root";
    $password = "";
    $database = "bancogeral";

    // Conecta-se ao banco de dados
    $conn = new mysqli($servername, $username, $password, $database);

    // Verifica a conexão
    if ($conn->connect_error) {
        die("Erro de conexão: " . $conn->connect_error);
    }

    // Recebe os dados do formulário
    $mercado = $_POST['mercados'];
    $cidade = $_POST['Localização'];
    $endereco = $_POST['Endereço'];

    $sql = "INSERT INTO mercados (mercados, Localização, Endereço) VALUES ('$mercado', '$cidade', '$endereco')";

    if ($conn->query($sql) === TRUE) {
    }
   else {
      }
    $conn->close();
}
?>


<!DOCTYPE html>
<html lang="pt-br">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Parceria</title>
  <link href="style.css" rel="stylesheet" type="text/css" />
</head>
<body>
  <body>
    <header>
      <div class="container-grid cabecalho">
          <a href="index.html"><img src="img/logo.png" alt="Logo MarketCycle" width="282" height="90"></a>
          <nav id="menu" class="menu">
              <a href="index.html">Início</a>
              <a href="index2.php">Mercados Parceiros</a>
              <a href="index3.php">Tornar-se Parceiro</a>
          </nav>      
      </div>
    </header>
    <section id="carrossel" class="banner banner-3">
      <div class="container-grid posicionamento-banner">
          <div class="conteudo-banner">
              <h1>Quer se tornar um parceiro?</h1>
          </div>
      </div>
    </section>
  <div class="Cinza3">
    <h1 class="subtitulo2">Informe seus dados abaixo e entraremos em contato o quanto antes:</h1>
    <div class="inputs">
      <form action="index3.php" method="post">
        <div class="entrar">
          <h1 class="textinho">Nome: </h1>
          <input type="text" name="nome" class="res">
        </div>
        <div class="entrar">
          <h1 class="textinho">Email: </h1>
          <input type="text" name="email" class="res">
        </div>
        <div class="entrar">
          <h1 class="textinho">Telefone: </h1>
          <input type="text" name="telefone" class="res">
        </div>
        <div class="entrar">
          <h1 class="textinho">Mercado: </h1>
          <input type="text" name="mercados" class="res">
        </div>
        <div class="entrar">
          <h1 class="textinho">Cidade: </h1>
          <input type="text" name="Localização" class="res">
        </div>
        <div class="entrar">
          <h1 class="textinho">Endereço: </h1>
          <input type="text" name="Endereço" class="res">
        </div>
        <button class="submeter" id="bs">Submeter</button>
      </form>
    </div>
  </div>
  <footer>
    <div class="container rodape">
        <div class="links-footer">
            <div>
                <h2>Links Úteis</h2>
                <ul>
                    <li><a href="#">Suporte</a></li>
                    <li><a href="#">Central de Ajuda</a></li>
                    <li><a href="#">Contato</a></li>
                </ul>
            </div>
            <div>
                <h2>Páginas</h2>
                <ul>
                    <li><a href="index.html">Início</a></li>
                    <li><a href="index2.php">Mercados Parceiros</a></li>
                    <li><a href="index3.php">Tornar-se Parceiros</a></li>
                </ul>
            </div>
        </div>
        <div class="sociais">
            <p>Cadastre-se para saber mais!</p>

            <form action="">
                <input id="campo-email" type="email" placeholder="E-mail" required>
                <button onclick="cadastrarNewsletter()">Cadastrar</button>
            </form>

            <div class="siga-nos">
                <h2>Siga-nos em:</h2>
                <a href="#"><img src="img/logo-instagram.png" alt="Logo do Instagram"></a>
                <a href="#"><img src="img/logo-facebook.png" alt="Logo do Facebook"></a>
                <a href="#"><img src="img/logo-yt.png" alt="Logo do Youtube"></a>
            </div>
        </div>
    </div>
</footer>
  <script src="script.js"></script>
</body>
</html>