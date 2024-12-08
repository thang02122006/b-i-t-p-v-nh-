#include <stdio.h>

int main() {
    int arr[100], size = 0;
    int choice, element, position;
    
    do {
        printf("\nMENU\n");
        printf("1: Nhap so phan tu va gia tri cho mang\n");
        printf("2: In ra cac phan tu trong mang\n");
        printf("3: Dem so luong cac so nguyen to trong mang\n");
        printf("4: Tim so hoan hao\n");
        printf("5: Tim gia tri nho thu hai trong mang\n");
        printf("6: Tim gia tri lon thu hai trong mang\n");
        printf("7: Them mot phan tu vao vi tri ngau nhien trong mang\n");
        printf("8: Xoa mot phan tu tai vi tri cu the\n");
        printf("9: Sap xep mang theo thu tu giam dan\n");
        printf("10: Sap xep mang theo thu tu tang dan\n");
        printf("11: Tim kiem phan tu trong mang\n");
        printf("12: Sap xep dua so chan len truoc so le xuong cuoi mang va in ra\n");
        printf("13: Xoa toan bo phan tu trung lap trong mang va hien thi toan bo phan tu doc nhat co trong mang\n");
        printf("14: Dao nguoc thu tu cac phan tu co o trong mang\n");
        printf("15: Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap so phan tu: ");
                scanf("%d", &size);
                printf("Nhap cac phan tu cho mang:\n");
                for (int i = 0; i < size; i++) {
                    printf("nhap gia tri %d = ", i+1);
                    scanf("%d", &arr[i]);
                }
                break;              
            case 2:
                printf("gia tri cua mang la: \n");
                for (int i = 0; i < size; i++) {
                    printf("arr[%d]=%d\n",i, arr[i]);
                }
                printf("\n");
                break;               
            case 3:
                {
                    int primeCount = 0;
                    for (int i = 0; i < size; i++) {
                        int num = arr[i];
                        if (num <= 1) continue; 
                        bool isPrime = true;
                        for (int j = 2; j * j <= num; j++) {
                            if (num % j == 0) {
                                isPrime = false;
                                break;
                            }
                        }
                        if (isPrime) primeCount++;
                    }
                    printf("So luong cac so nguyen to trong mang: %d\n", primeCount);
                }
                break;
            case 4:
            	if(size > 0){
					for(int i = 0; i < size; i++){
						int sum = 0;
						int n = arr[i];
						for(int j = 1; j < n;j++){
							if(n % j ==0){
								sum += j;
							}
						}
						if(n == sum){
							printf("so hoan hao la: %d\n", n);
						}
					}
				}else{
					printf("chua khoi tao mang");
				}
				break;   
            case 5:
                if (size < 2) {
                    printf("Khong co gia tri nho thu hai trong mang\n");
                } else {
                    int first = arr[0], second = arr[1];
                    if (first > second) {
                        first = arr[1];
                        second = arr[0];
                    }
                    for (int i = 2; i < size; i++) {
                        if (arr[i] < first) {
                            second = first;
                            first = arr[i];
                        } else if (arr[i] < second && arr[i] != first) {
                            second = arr[i];
                        }
                    }
                    printf("Gia tri nho thu hai trong mang: %d\n", second);
                }
                break;
            case 6:
            	if(size > 0){
				int max = arr[0];
				int max2;
				for(int i = 1; i < size; i++){
					if(max < arr[i]){
						max = arr[i];
					}
				}
				for(int i = 0; i < size; i++){
					if(max2 < arr[i]&&arr[i] < max){
						max2 = arr[i];
					}
				}
				printf("Phan tu lon thu 2 cua mang la: %d", max2);
				}else{
					printf("chua khoi tao mang");
				}
				break;    
            case 7:
                printf("Nhap gia tri can them: ");
                scanf("%d", &element);
                printf("Nhap vi tri can them: ");
                scanf("%d", &position);
                if (position >= 0 && position <= size) {
                    for (int i = size; i > position; i--) {
                        arr[i] = arr[i - 1];
                    }
                    arr[position] = element;
                    size++;
                    printf("Mang sau khi thêm phan tu la: ");
                    for (int i = 0; i < size; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                } else {
                    printf("Vi trí không hop le\n");
                }
                break;
                
            case 8:
                printf("Nhap vi tri can xoa: ");
                scanf("%d", &position);
                if (position >= 0 && position < size) {
                    for (int i = position; i < size - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    size--;
                    printf("Mang sau khi xoa phan tu: ");
                    for (int i = 0; i < size; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                } else {
                    printf("Vi tri khong hop le\n");
                }
                break;
                
            case 9:
            	if(size>0){
                  for (int i = 0; i < size - 1; i++) {
                        for (int j = i + 1; j < size; j++) {
                            if (arr[i] < arr[j]) {
                                int temp = arr[i];
                                arr[i] = arr[j];
                                arr[j] = temp;
                            }
                        }
                    }
                    printf("Mang sau khi sap xep giam dan: ");
                    for (int i = 0; i < size; i++) {
                        printf("%d ", arr[i]);
                    }
                    }else{
					printf("chua khoi tao mang");
				    }
                break;
            case 10:
            	if(size > 0){
				for(int i = size - 1; i > 0; i--){
					for(int j = 0; j < i; j++){
						if(arr[j] > arr[j+1]){
							int temp = arr[j];
							arr[j] = arr[j+1];
							arr[j+1] = temp;
						}
					}
				}
				printf("Mang sau khi sap xep giam dan: ");
                    for (int i = 0; i < size; i++) {
                        printf("%d ", arr[i]);
                    }
				}else{
					printf("chua khoi tao mang");
				}
				break;
            case 11:
                printf("Nhap gia tri can tim: ");
                scanf("%d", &element);
                int found = -1;
                for (int i = 0; i < size; i++) {
                    if (arr[i] == element) {
                        found = i;
                        break;
                    }
                }
                if (found == -1) {
                    printf("Phan tu %d khong co trong mang\n", element);
                } else {
                    printf("Phan tu %d tim thay tai vi tri %d\n", element, found);
                }
                break;
    }
    } while (choice != 15);

    return 0;
}

