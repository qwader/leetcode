/**
 * There are two sorted arrays A and B of size m and n respectively. 
 * Find the median of the two sorted arrays. 
 * The overall run time complexity should be O(log (m+n)).
**/


class Solution {
    
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if(m == 0 && n == 0) return 0;
        if(m == 0){
            return check_one(B, n);
        }
        if(n == 0){
            return check_one(A, m);
        }
        if(A[m - 1] <= B[0]){
            return check_combine(A, m, B, n);
        }
        if(A[0] >= B[n - 1]){
            return check_combine(B, n, A, m);
        }
        if(m <= n){
            return findMedian(A, m, B, n);
        }
        else{
            return findMedian(B, n, A, m);
        }
    }
    
    double check_one(int *Arr, int n){
        return (n % 2 == 0) ? (Arr[n / 2 - 1] + Arr[n / 2]) / 2.0 : Arr[n / 2];
    }
    
    double check_combine(int *F, int f, int *S, int s){
        if(f == s){
            return (F[f - 1] + S[0]) / 2.0;
        }
        else if(f > s){
            return check_one(F + s, f - s);
        }
        else {
            return check_one(S, s - f);
        }
    }
    
    double findMedian(int *F, int f, int *S, int s){
        if(f == 2){
            if(F[1] <= S[s / 2]){
                if(F[0] >= S[s / 2 - 1]){
                    if(s % 2 == 0){
                        return (F[0] + F[1]) / 2.0;
                    }
                    else {
                        return F[1];
                    }
                }
                else{
                    return findMedian(F + 1, 1, S, s - 1);
                }
            }
            else if(F[0] >= S[s / 2]){
                if(F[1] <= S[s / 2 + 1]){
                    if(s % 2 == 0){
                        return (S[s / 2] + F[0]) / 2.0;
                    }
                    else {
                        return F[0];
                    }
                }
                else{
                    return findMedian(F, 1, S + 1, s - 1);
                }
            }
            else{
                if((s % 2 == 0) && (F[0] > S[ s / 2 - 1])){
                    return (F[0] + S[s / 2]) / 2.0;
                }
                else {
                    return check_one(S, s);
                }
            }
        }
        else if(f == 1){
            if(s == 1){
                return (F[0] + S[0]) / 2.0;
            }
            if(s % 2 == 0){
                if(F[0] <= S[s / 2]){
                    if(F[0] >= S[s / 2 - 1]){
                        return F[0];
                    }
                    else {
                        return S[s / 2 - 1];
                    }
                }
                else {
                    return S[s / 2];
                }
            }
            else{
                if(F[0] <= S[s / 2]){
                    if(F[0] >= S[s / 2 - 1]){
                        return (F[0] + S[s / 2]) / 2.0;
                    }
                    else{
                        return (S[s / 2 - 1] + S[s / 2]) / 2.0;
                    }
                }
                else{
                    if(F[0] <= S[s / 2 + 1]){
                        return (F[0] + S[s / 2]) / 2.0;
                    }
                    else {
                        return (S[s / 2] + S[s / 2 + 1]) / 2.0;
                    }
                }
            }
        }
        else{
            if(F[f / 2] <= S[s / 2]){
                return findMedian(F + (f - 1) / 2, f - (f - 1) / 2, S, s - (f - 1) / 2);
            }
            else{
                return findMedian(F, f - (f - 1) / 2, S + (f - 1) / 2, s - (f - 1) / 2);
            }
        }
    }
};
