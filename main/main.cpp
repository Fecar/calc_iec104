#include <iostream>

int op;
char out;
bool run{true};

// Funcao Menu
void menu() {
  bool val_op{false};

  while (!val_op) {
    std::string s_op;
    std::cout << "****************** Welcome! ******************" << '\n';
    std::cout << "Opcoes do programa:" << '\n';
    std::cout << "[1] Calcular o IOA DECIMAL para 3 OCTETOS" << '\n';
    std::cout << "[2] Calcular 3 OCTETOS para IOA DECIMAL" << '\n';
    std::cout << "[3] Calcular ASDU para CASDU1 e CASDU2" << '\n';
    std::cout << "[4] Calcular CASDU1 e CASDU2 para ASDU" << '\n';
    std::cout << "[0] Sair do Programa" << '\n';
    std::cout << "Digite a opcao: ";
    std::getline(std::cin, s_op);
    std::cin.ignore();

    for (char c : s_op) {
      if (!std::isdigit(c)) {
        val_op = false;
        break;
      } else {
        val_op = true;
      }
    }
    s_op = s_op[0];
    op = std::stoi(s_op);
    system("clear");
  }
}

// Funcao de validacao de dados, valida se o numero esta entre 0 e 255
bool check_oct(std::string str) {
  int x = std::stoi(str);
  return x >= 0 && x <= 255;
}

// Funcao de validacao de dados, valida se o numero esta entre 0 e 65535
bool check_dec(std::string str) {
  int x = std::stoi(str);
  return x >= 0 && x <= 65535;
}

void calc_ioa_oct(std::string str) {
  int x, y, z, num = std::stoi(str);

  // ioa1
  x = num % 256;

  // ioa2
  y = (num / 256) % 256;

  // ioa3
  z = (num / (256 * 256)) % 256;

  // Imprime os IOAs na tela x = ioa1, y = ioa2, z = ioa3
  std::cout << "O IOA1 eh: " << x << '\n';
  std::cout << "O IOA2 eh: " << y << '\n';
  std::cout << "O IOA3 eh: " << z << '\n';
}

void calc_ioa_dec(std::string str1, std::string str2, std::string str3) {
  int out, num1, num2, num3;
  num1 = std::stoi(str1);
  num2 = std::stoi(str2);
  num3 = std::stoi(str3);

  out = (num3 * 35536) + (num2 * 256) + (num1);

  // Imprime os IOA Decimal na tela
  std::cout << "O IOA Decimal eh: " << out << '\n';
}

void calc_asdu(std::string str) {
  int x, y, num = std::stoi(str);

  // CASDU1
  x = num % 256;

  // CASDU2
  y = num / 256;

  // Imprime os CASDUs na tela x = casdu1, y = casdu2
  std::cout << "O CASDU1 eh: " << x << '\n';
  std::cout << "O CASDU2 eh: " << y << '\n';
}

void calc_casdu(std::string str1, std::string str2) {
  int out, num1, num2;
  num1 = std::stoi(str1);
  num2 = std::stoi(str2);

  out = (num2 * 256) + (num1);

  // Imprime os CASDUs na tela x = casdu1, y = casdu2
  std::cout << "O ASDU eh: " << out << '\n';
}

int main() // Funcao principal
{
  do {
    menu();
    if (op != 0) {
      std::string s_addr104, s_ioa1, s_ioa2, s_ioa3, s_asdu, s_casdu1, s_casdu2;
      bool val_case1{false}, val_case2{false}, val_case3{false},
          val_case4{false};

      switch (op) {
      case 1:
        // Aqui realiza o laco de repeticao para tratar os numeros gerador pelo
        // usuario.
        while (!val_case1) {
          std::cout << "Digite o IOA DECIMAL (0 ... 65535): ";
          std::getline(std::cin, s_addr104);

          bool s_addr104_num{true};

          for (char c : s_addr104) {
            if (!std::isdigit(c)) {
              s_addr104_num = false;
              break;
            }
          }

          if (s_addr104_num && check_dec(s_addr104)) {
            val_case1 = true;
          } else {
            std::cout
                << "Digite apenas NUMEROS entre 0 ... 65535 para ADDR104!!!"
                << '\n';
            system("pause");
            system("clear");
          }
        }
        // Funcao de Calculo ...

        calc_ioa_oct(s_addr104);
        system("pause");
        system("clear");

        break;
      case 2:
        // Aqui realiza o laco de repeticao para tratar os numeros gerador pelo
        // usuario.
        while (!val_case2) {
          std::cout << "Digite o IOA1 (0 ... 255): ";
          std::getline(std::cin, s_ioa1);
          std::cout << "Digite o IOA2 (0 ... 255): ";
          std::getline(std::cin, s_ioa2);
          std::cout << "Digite o IOA3 (0 ... 255): ";
          std::getline(std::cin, s_ioa3);

          bool s_ioa1_num{true};

          for (char c : s_ioa1) {
            if (!std::isdigit(c)) {
              s_ioa1_num = false;
              break;
            }
            for (char c : s_ioa2) {
              if (!std::isdigit(c)) {
                s_ioa1_num = false;
                break;
              }
              for (char c : s_ioa3) {
                if (!std::isdigit(c)) {
                  s_ioa1_num = false;
                  break;
                }
              }
            }
          }

          if (s_ioa1_num && check_oct(s_ioa1) && check_oct(s_ioa2) &&
              check_oct(s_ioa3)) {
            val_case2 = true;
          } else {
            std::cout << "Digite apenas NUMEROS entre 0 ... 255 para os IOAs!!!"
                      << '\n';
            system("clear");
          }
        }
        // Funcao de Calculo ...

        calc_ioa_dec(s_ioa1, s_ioa2, s_ioa3);
        system("pause");
        system("clear");

        break;
      case 3:
        // Aqui realiza o laco de repeticao para tratar os numeros gerador pelo
        // usuario.
        while (!val_case3) {
          std::cout << "Digite o ASDU (0 ... 65535): ";
          std::getline(std::cin, s_asdu);

          bool s_asdu_num{true};

          for (char c : s_asdu) {
            if (!std::isdigit(c)) {
              s_asdu_num = false;
              break;
            }
          }

          if (s_asdu_num && check_dec(s_asdu)) {
            val_case3 = true;
          } else {
            std::cout << "Calculou o CASDU1 e CASDU2!!!" << '\n';
            system("pause");
          }
        }

        // Funcao de Calculo
        calc_asdu(s_asdu);
        system("pause");
        system("clear");

        break;
      case 4:
        // Aqui realiza o laco de repeticao para tratar os numeros gerador pelo
        // usuario.
        while (!val_case4) {
          std::cout << "Digite o CASDU1 (0 ... 255): ";
          std::getline(std::cin, s_casdu1);
          std::cout << "Digite o CASDU2 (0 ... 255): ";
          std::getline(std::cin, s_casdu2);

          bool s_casdu{true};

          for (char c : s_casdu1) {
            if (!std::isdigit(c)) {
              s_casdu = false;
              break;
            }
            for (char c : s_casdu2) {
              if (!std::isdigit(c)) {
                s_casdu = false;
                break;
              }
            }
          }

          if (s_casdu && check_dec(s_casdu1) && check_dec(s_casdu2)) {
            val_case4 = true;
          } else {
            std::cout
                << "Digite apenas NUMEROS entre 0 ... 255 para os CASDUs!!!";
            system("pause");
          }
        }

        // Funcao de Calculo
        calc_casdu(s_casdu1, s_casdu2);
        system("pause");
        system("clear");

        break;
      default:
        std::cout << "Digite apenas as opcoes:" << '\n';
        std::cout << "[1] ou [2] ou [3] ou [4] ou [0]" << '\n';
        system("pause");
        system("clear");
        break;
      }
    } else {
      std::cout << "Deseja realmente sair ? [Y/n]: ";
      std::cin >> out;
      std::cin.ignore();
      out = toupper(out);
      if (out == 'N') {
        run = true;
        system("clear");
      } else if (out == 'Y') {
        run = false;
        std::cout << "\nVou sentir saudades :D \n\nSee you later!!!!" << '\n';
        system("pause");
      } else {
        system("clear");
        std::cout << "Digite Apenas 'Y' ou 'n' ..." << '\n';
      }
    }
  } while (run);

  return 0;
}
