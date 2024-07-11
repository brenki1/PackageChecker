# PackageChecker

Programa simples em C feito para uso pessoal. Compara dois arquivos de texto que listam pacotes instalados pelo pacman, e indica a diferença entre os dois, útil para novas instalações ou após uma formatação.

Pode ser usado para outros propósitos que envolvem comparar dois arquivos de texto que possuem uma lista.

# Como obter uma lista de todos os pacotes atualmente instalados pelo Pacman?

Se quiser, crie um diretório para guardar o arquivo .txt dos pacotes

**Ex:** $`cd Documentos` 
$`mkdir listapkgs` 
$`cd listapkgs`

**Após escolher o diretório, digite** `pacman -Qqe > pkglist.txt` que criará um arquivo de texto ***pkglist*** no diretório selecionado, com todos os pacotes instalados explicitamente, incluindo pacotes AUR.

Caso queira criar uma lista separada apenas com pacotes AUR ou instalados externamente, digite `pacman -Qqem > foreignpkglist.txt` 