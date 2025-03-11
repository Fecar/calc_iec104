#include <iostream>
// #include <sstream>
// #include <cctype>
#include <unistd.h>

int op;
char out;
bool run{true};

// Função Menu
void menu() {
  bool val_op{false};

  while (!val_op) {
    std::string s_op;
    std::cout << "==================== Wellcome! ====================\n"
                 "Options:\n"
                 "[1] Calculate the Decimal IOA to 3 Octets\n"
                 "[2] Calculate 3 Octets to Decimal IOA\n"
                 "[3] Calculate ASDU to CASDU1 and CASDU2\n"
                 "[4] Calculate CASDU1 and CASDU2 to ASDU\n"
                 "[0] Exit\n"
                 "====================================================\n"
                 "Enter the option: ";
    std::getline(std::cin, s_op);

    if (!s_op.empty() && s_op.find_first_not_of("0123456789") == std::string::npos) {
      try {
        op = std::stoi(s_op);
        val_op = true;
        system("clear");
      } catch (const std::out_of_range &e) {
        std::cout << "Erro: " << e.what() << "\nNumber out of range." << std::endl;
        sleep(3);
        system("clear");
      }
    } else {
      std::cout << "\nInvalid input! Enter a number, please." << '\n';
      sleep(2);
      system("clear");
    }
  }
}

bool valid_numb(std::string str) {
  bool b_num{true};

  for (char c : str) {
    if (!std::isdigit(c)) {
      b_num = false;
    }
  }
  return b_num;
}

// Função de validação de dados, valida se o numero está entre 0 e 255
bool check_oct(std::string str) {
  int x = std::stoull(str);
  return (x >= 0 && x <= 255) && valid_numb(str);
}

// Função de validação de dados, valida se o numero está entre 0 e 65535
bool check_dec(std::string str) {
  int x = std::stoull(str);
  return x >= 0 && x <= 9127215 && valid_numb(str);
}

// Função que calcula o IOA Decimal para Octeto
void calc_ioa_oct(std::string str) {
  int x, y, z, num = std::stoull(str);

  // ioa1
  x = num % 256;

  // ioa2
  y = (num / 256) % 256;

  // ioa3
  z = (num / (256 * 256)) % 256;

  // Imprime os IOAs na tela x = ioa1, y = ioa2, z = ioa3
  std::cout << "The IOA1 is: " << x << '\n';
  std::cout << "The IOA2 is: " << y << '\n';
  std::cout << "The IOA3 is: " << z << '\n';
}

// Função que calcula o Octeto para IOA Decimal
void calc_ioa_dec(std::string str1, std::string str2, std::string str3) {
  int out, num1, num2, num3;
  num1 = std::stoull(str1);
  num2 = std::stoull(str2);
  num3 = std::stoull(str3);

  // Imprime os IOA Decimal na tela
  std::cout << "The Decimal IOA is: " << (num3 * 35536) + (num2 * 256) + (num1) << '\n';
}

// Função que calcula o ASDU
void calc_asdu(std::string str) {
  int x, y, num = std::stoull(str);

  // CASDU1
  x = num % 256;

  // CASDU2
  y = num / 256;

  // Imprime os CASDUs na tela x = casdu1, y = casdu2
  std::cout << "The CASDU1 is: " << x << '\n';
  std::cout << "The CASDU2 is: " << y << '\n';
}

// Função que calcula o CASDU
void calc_casdu(std::string str1, std::string str2) {
  int num1, num2;
  num1 = std::stoull(str1);
  num2 = std::stoull(str2);

  // Imprime os ASDU na tela
  std::cout << "The ASDU is: " << (num2 * 256) + (num1) << '\n';
}

int main() {
  do {
    menu();
    if (op != 0) {
      std::string s_addr104, s_ioa1, s_ioa2, s_ioa3, s_asdu, s_casdu1, s_casdu2;
      bool val_case1{false}, val_case2{false}, val_case3{false}, val_case4{false};

      switch (op) {
      case 1:
        // Aqui realiza o laço de repetição para tratar os numeros gerado pelo usuario.
        while (!val_case1) {
          std::cout << "Enter the Decimal IOA (0 to 65535): ";
          std::getline(std::cin, s_addr104);

          if (check_dec(s_addr104) && valid_numb(s_addr104)) {
            val_case1 = true;

            // Função de Calculo
            calc_ioa_oct(s_addr104);
            std::cout << "\nPress Enter to continue ...:";
            std::cin.get();
            system("clear");
          } else {
            std::cout << "\nOnly enter numbers between 0 and 65535 for ADDR104!" << '\n';
            sleep(3);
            system("clear");
          }
        }

        break;

      case 2:
        // Aqui realiza o laço de repetição para tratar os numeros gerado pelo usuario.
        while (!val_case2) {
          std::cout << "Enter the IOA1 (0 ... 255): ";
          std::getline(std::cin, s_ioa1);
          std::cout << "Enter the IOA2 (0 ... 255): ";
          std::getline(std::cin, s_ioa2);
          std::cout << "Enter the IOA3 (0 ... 255): ";
          std::getline(std::cin, s_ioa3);

          bool var1;

          var1 = check_oct(s_ioa1) && check_oct(s_ioa2) && check_oct(s_ioa3);

          if (var1) {
            val_case2 = true;
            // Função de Calculo

            calc_ioa_dec(s_ioa1, s_ioa2, s_ioa3);
            std::cout << "\nPress Enter to continue ...:";
            std::cin.get();
            system("clear");
          } else {
            std::cout << "Enter only numbers between 0 and 255 for IOAs!" << '\n';
            sleep(2);
            system("clear");
          }
        }

        break;
      case 3:
        // Aqui realiza o laço de repetição para tratar os numeros gerado pelo usuario.
        while (!val_case3) {
          std::cout << "Enter the ASDU (0 ... 65535): ";
          std::getline(std::cin, s_asdu);

          if (check_dec(s_asdu)) {
            val_case3 = true;

            // Função de Calculo
            calc_asdu(s_asdu);
            std::cout << "\nPress Enter to continue ...:";
            std::cin.get();
            system("clear");
          } else {
            std::cout << "Enter only numbers between 0 e 65535 for ASDU!" << '\n';
            sleep(2);
            system("clear");
          }
        }

        break;
      case 4:
        // Aqui realiza o laço de repetição para tratar os numeros gerado usuario.
        while (!val_case4) {
          std::cout << "Enter the CASDU1 (0 ... 255): ";
          std::getline(std::cin, s_casdu1);
          std::cout << "Enter the CASDU2 (0 ... 255): ";
          std::getline(std::cin, s_casdu2);

          if (check_dec(s_casdu1) && check_dec(s_casdu2)) {
            val_case4 = true;

            // Função de Calculo
            calc_casdu(s_casdu1, s_casdu2);
            std::cout << "\nPress Enter to continue ...:";
            std::cin.get();
            system("clear");
          } else {
            std::cout << "Enter only numbers between 0 e 255 for CASDUs!!!";
            sleep(2);
            system("clear");
          }
        }

        break;
      default:
        std::cout << "Enter only the options below:" << '\n';
        std::cout << "[1] or [2] or [3] or [4] or [0]" << '\n';
        sleep(2);
        system("clear");
        break;
      }
    } else {
      std::cout << "Do you really want to leave ? [Y/n]: ";
      std::cin >> out;
      std::cin.ignore();
      out = toupper(out);
      if (out == 'N') {
        run = true;
        system("clear");
      } else if (out == 'Y') {
        run = false;
        std::cout << "\nI will miss you =( \n\nSee you later!!!!" << '\n';
        sleep(1);
      } else {
        system("clear");
        std::cout << "Enter only 'Y' or 'n' ..." << '\n';
        sleep(3);
      }
    }
  } while (run);

  return 0;
}
