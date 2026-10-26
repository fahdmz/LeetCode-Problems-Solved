/* =======================================================
 * File: problem.c
 * Deskripsi:
 *   Implementasi fungsi untuk mencari level pada binary tree
 *   yang memiliki jumlah nilai node (sum) terbesar.
 *
 *   Level dari root adalah 1, level anak-anaknya adalah 2, dan seterusnya.
 *   Jika ada lebih dari satu level dengan sum maksimal yang sama,
 *   kembalikan level terkecil (paling atas).
 *
 * ======================================================= */

#include <stdio.h>
#include <stdlib.h>
#include "bintree.h" /* Asumsikan ADT bintree sudah disediakan */

/* =======================================================
 * Fungsi Utama: levelMaxSum
 * =======================================================
 *
 * Deskripsi:
 *   Mengembalikan level dengan jumlah nilai node (sum) terbesar
 *   dari sebuah binary tree.
 *
 * Spesifikasi:
 *   I.S.  : root terdefinisi (mungkin NULL)
 *   F.S.  : Mengembalikan nilai level (integer >= 1)
 *           dengan sum tertinggi.

 * Catatan:
 *   - Jumlah node n ∈ [1, 10^4].
 *   - Nilai node ∈ [-10^5, 10^5].
 *   - Jika ada lebih dari satu level dengan sum maksimal yang sama,
 *     kembalikan level terkecil (paling atas).
 */

/* =======================================================
 * ----------------------- CONTOH 1 ------------------------
 * =========================================================
 * Misal pohon terbentuk:
 *
 *           (1)
 *          /   \
 *        (7)   (0)
 *       /  \
 *     (7)  (-8)
 *
 * Level 1 → sum = 1
 * Level 2 → sum = 7 + 0 = 7
 * Level 3 → sum = 7 + (-8) = -1
 *
 * Hasil: level 2 (7 adalah sum tertinggi)
 * Output : 2
 * ======================================================= */

/*
 * ----------------------- CONTOH 2 ------------------------
 * Misal pohon 2:
 *
 *              (989)
 *                 \
 *                (10250)
 *               /      \
 *           (98693)   (-89388)
 *                      \
 *                      (-32127)
 *
 * Level 1 → sum = 989
 * Level 2 → sum = 10250
 * Level 3 → sum = 98693 + (-89388) = 929305
 * Level 4 → sum = -32127
 *
 * Jadi level dengan jumlah terbesar adalah level 2 (sum = 10250)
 * Output  : 2
 * --------------------------------------------------------
 */

int levelMaxSum(BinTree root)
{
    if (root == NULL)
    {
        return 0; /* Tidak ada node */
    }

    /* Queue sederhana (array) */
    BinTree queue[10005];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int level = 1;
    int maxLevel = 1;
    long long maxSum = -1000000000000000000LL; /* sangat kecil */

    while (front < rear)
    {
        int size = rear - front; /* jumlah node di level ini */
        long long sumLevel = 0;

        for (int i = 0; i < size; i++)
        {
            BinTree curr = queue[front++];
            sumLevel += ROOT(curr);

            if (LEFT(curr) != NULL)
            {
                queue[rear++] = LEFT(curr);
            }
            if (RIGHT(curr) != NULL)
            {
                queue[rear++] = RIGHT(curr);
            }
        }

        /* Update max sum & level */
        if (sumLevel > maxSum)
        {
            maxSum = sumLevel;
            maxLevel = level;
        }

        level++;
    }

    return maxLevel;
}