/*
* AES encryption / decryption;
*
* Copyright 2014, Juncheng Ma <majch2011@gmail.com>
*
* You should have received a copy of the GNU General Public License
* along with aes library. If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <string.h>

#include "libaes/aes.h"

void printBytes(unsigned char b[], int len) {
  int i;
  for (i=0; i<len; i++)
    printf("%d ", b[i]);
  printf("\n");
}

// ===================== test ============================================
int main() {
  int i;

  unsigned char block[16];
  for(i = 0; i < 16; i++)
    block[i] = 0x11 * i;

  printf(" original block£º"); printBytes(block, 16);

  unsigned char key[16 * (14 + 1)];
  int keyLen = 32, maxKeyLen=16 * (14 + 1), blockLen = 16;
  for(i = 0; i < keyLen; i++)
    key[i] = i;

  aes_init(key, keyLen);

  aes_encrypt(block, 16, block);

  printf("encrypted block£º"); printBytes(block, blockLen);

  aes_decrypt(block, 16, block);

  printf("decrypted block£º"); printBytes(block, blockLen);

  aes_close();

  return 0;
}