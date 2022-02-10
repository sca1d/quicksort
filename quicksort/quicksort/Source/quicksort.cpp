// quicksort.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <stdio.h>

template <typename T>
void swap(T* a, T* b) {

	T t = *a;
	*a = *b;
	*b = t;

}

template <typename T>
T partition(T array[], int l, int r) {

	T pivot = array[r];
	T i = (l - 1);

	for (T j = l; j <= r - 1; j++) {
		if (array[j] <= pivot) {
			i++;
			swap(&array[i], &array[j]);
		}
	}

	swap(&array[i + 1], &array[r]);
	return (i + 1);

}

template <typename T>
void quicksort(T array[], int l, int r) {

	if (l < r) {
		T pivot = partition(array, l, r);
		quicksort(array, l, pivot - 1);
		quicksort(array, pivot + 1, r);
	}

}

int main() {

	int i;
	unsigned int array[10] = { 3, 6, 1, 7, 2, 0, 4, 5, 9, 8 };

	printf("array: ");
	for (i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

	quicksort(array, 0, sizeof(array) / sizeof(array[0]) - 1);

	printf("sorted array: ");

	for (i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

	return 0;

}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
