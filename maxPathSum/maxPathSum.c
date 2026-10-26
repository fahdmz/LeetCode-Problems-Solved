#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

/* =======================================================
 * Fungsi Utama: maxPathSum
 * =======================================================
 *
 * Deskripsi:
 *   Mengembalikan nilai maksimum yang bisa dicapai oleh sebuah path
 *   pada binary tree.
 *
 * Spesifikasi:
 *   I.S.  : root terdefinisi (boleh NULL)
 *   F.S.  : Mengembalikan integer berupa maksimum path sum.
 *
 * Catatan:
 *   - Path boleh:
 *       * hanya satu node
 *       * melalui root atau tidak melalui root
 *       * melalui kiri → parent → kanan
 *       * setiap node hanya boleh dilewati satu kali.
 *       * dimulai dan diakhiri di node mana pun,
 *   - Setiap node ∈ [-10^5, 10^5]
 *   - Jumlah node n ∈ [1, 10^4]
 *
 * =======================================================
 */

/* =======================================================
 * ----------------------- CONTOH 1 -----------------------
 * =======================================================
 *
 *           (1)
 *          /   \
 *        (2)   (3)
 *
 * Semua path dan sum-nya:
 *  Path terbaik: 2 → 1 → 3 = 6
 *
 * Output: 6
 * =======================================================
 */

/* =======================================================
 * ----------------------- CONTOH 2 ------------------------
 * =======================================================
 *
 *                 (-10)
 *                 /    \
 *              (9)     (20)
 *                     /    \
 *                   (15)   (7)
 *
 * Path terbaik: 15 → 20 → 7 = 42
 *
 * Output: 42
 * --------------------------------------------------------
 */

int maxPathSumHelper(BinTree p, int *globalMax)
{
    if (p == NULL)
    {
        return 0;
    }

    int left = maxPathSumHelper(LEFT(p), globalMax);
    int right = maxPathSumHelper(RIGHT(p), globalMax);

    /* Abaikan path negatif */
    if (left < 0)
        left = 0;
    if (right < 0)
        right = 0;

    /* Path terbaik yang melewati node ini */
    int current = ROOT(p) + left + right;

    if (current > *globalMax)
    {
        *globalMax = current;
    }

    /* Path terbaik ke parent (satu arah) */
    return ROOT(p) + (left > right ? left : right);
}

int maxPathSum(BinTree root)
{
    if (root == NULL)
    {
        return 0;
    }

    /* Nilai minimum manual (lebih kecil dari -10^5 * 10^4) */
    int globalMax = -1000000000;

    maxPathSumHelper(root, &globalMax);
    return globalMax;
}