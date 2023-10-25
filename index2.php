<!DOCTYPE html>
<html lang="pt-br">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>MarcadosParceiros</title>
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-T3c6CoIi6uLrA9TneNEoa7RxnatzjcDSCmG1MXxSR1GAsXEV/Dwwykc2MPK8M2HN" crossorigin="anonymous">
  <link href="style.css" rel="stylesheet" type="text/css" />

</head>
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
  <section id="carrossel" class="banner banner-2">
    <div class="container-grid posicionamento-banner">
        <div class="conteudo-banner">
            <h1>Mercados Parceiros</h1>
        </div>
    </div>
  </section>
  <div class="Cinza2">
    <table class="tabela">
      <thead>
        <tr>
          <th>Mercado</th>
          <th>Localização</th>
          <th>Endereço</th>
        </tr>
      </thead>
      <tbody>
        <?php
        $servername = "localhost";
        $username = "root";
        $password = "";
        $database = "bancogeral";

        // cria conexao
        $connection = new mysqli($servername, $username, $password, $database, 3306);

        //query leitura das tabelas
        $sql = "SELECT * FROM mercados";
        $result = $connection->query($sql);

        //previne erro
        if ($connection->connect_error)
        {
          die("erro: " . $connection->connect_error);
        }

        //ler linhas
        while($row = $result->fetch_assoc())
        {
          echo "<tr>
            <td>" . $row["mercados"] . "</td>
            <td>" . $row["Localização"] . "</td>
            <td>" . $row["Endereço"] . "</td>
          </tr>";
        }
        ?>
      </tbody>
    </table>
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