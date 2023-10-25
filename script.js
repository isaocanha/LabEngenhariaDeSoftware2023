const valorPapel = 0.02;
const valorPlastico = 0.08;
const valorMetal = 0.10;
const valorVidro = 0.04;

function calcularDesconto() {
  const papel = parseFloat(document.getElementById('papel').value) || 0;
  const plastico = parseFloat(document.getElementById('plastico').value) || 0;
  const metal = parseFloat(document.getElementById('metal').value) || 0;
  const vidro = parseFloat(document.getElementById('vidro').value) || 0;

  const descontoTotal = (papel * valorPapel) + (plastico * valorPlastico) + (metal * valorMetal) + (vidro * valorVidro);
  
  document.getElementById('resultado').innerText = descontoTotal.toFixed(2);
}

document.getElementById('papel').addEventListener('input', calcularDesconto);
document.getElementById('plastico').addEventListener('input', calcularDesconto);
document.getElementById('metal').addEventListener('input', calcularDesconto);
document.getElementById('vidro').addEventListener('input', calcularDesconto);