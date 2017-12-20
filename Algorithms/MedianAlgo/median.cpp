//Filename: median.zp
//Author: Kyle Shake
//Date: 11/13/17
//Purpose: This Z+ program reads in 5 integers and finds the median of those 5 integers

#include <iostream>

using namespace std;

int main(){
//Get numbers from input
    int a;
    int b;
    int c;
    int d;
    int e;
    cout <<"Enter a number: ";
    cin >> a;
    cout << endl;
    cout <<"Enter a number: ";
    cin >> b;
    cout << endl;
    cout <<"Enter a number: ";
    cin >> c;
    cout << endl;
    cout <<"Enter a number: ";
    cin >> d;
    cout << endl;
    cout <<"Enter a number: ";
    cin >> e;
    


    int l;
    int nl;
    int m;
    int nh;
    int h;

    if (a > b){ // a > b
        if (a > c){ // a > b|c
            if(a > d){ // a > b|c|d
                if (a > e){ // a > b|c|d|e
                    h = a; // ---------------------------------------------------------------------------- a > b|c|d|e
                    if (b > c){ // a > b|d|e > c|d|e
                        if (b > d){ // a > b|e > c|d|e
                            if (b > e){ // a > b > c|d|e
                                nh = b; // -------------------------------------a > b > c|d|e
                                if (c > d){ // a > b > c|e > d|e
                                    if(c > e){ // a > b > c > d|e
                                        m = c;
                                    }else{ //a > b > e > c > d
                                        m = e;
                                    }
                                }else{ // a > b > d|e > c|e
                                    if (d > e){ // a > b > d > c|e
                                        m = d;
                                    }else { // a > b > e > d > c
                                        m = e;
                                    }
                                } // ------------------------------------------END a > b > c|d|e
                            }else{ // e >= b --> a > e > b > c|d
                                nh = e;
                                m = b;
                            }
                        }else{ // d >= b --> a > d|e > b|e > c|e
                            if (d > e){ // a > d > b|e > c|e
                                nh = d;
                            }else{ // e >= d --> a > e > d > b > c
                                nh = e;
                                 m = d;
                            }
                        }
                    }else{ //c >=b --> a > c|d|e > b|d|e
                        if (c > d){ // a > c|e > b|d|e
                            if (c > e){ // a > c > b|d|e
                                nh = c; // ----------------------------------- a > c > b|d|e
                                if (b > d){ // a > c > b|e > d|e
                                    if (b > e){ // a > c > b > d|e
                                        m = b;
                                    }else{ // e >= b --> a > c > e > b > d
                                        m = e;
                                    }
                                }else{ //d >= b --> a > c > d|e > b|e
                                    if (d > e){ // a > c > d > b|e
                                        m = d;
                                    }else{ // e >= d --> a > c > e > d > b
                                        m = e;
                                    }
                                } // ----------------------------------------- END a > c > b|d|e
                            }else{ // e >= c --> a > e > c > b|d
                                nh = e; 
                                 m = c;
                            }
                        }else{ // d >= c --> a > d|e > c|e > b|e
                            if (d > e){ // a > d > c|e > b|e
                                nh = d; //- -------------------------------------- a > d > b|c|e
                                if (c > e){ // a > d > c > b|e
                                    m = c;
                                }else{ // a > d > e > c > b
                                    m = e;
                                } // --------------------------------------------END a > d > b|c|e
                            }else{ // a > e > d > c > b
                                nh = e;
                                m = d;
                            }
                        } 
                    } // ---------------------------------------------------------------------------END a > b|c|d|e 
                }else{ // e > a > b|c|d ------------------------------------------------------------    e > a > b|c|d
                    h = e;
                    nh = a;
                    if (b > c){ // e > a > b|d > c|d
                        if (b > d){ // e > a > b > c|d
                            m = b;
                        }else{ // d >= b --> e > a > d > b > c
                            m = d;
                        }
                    }else{ // c >= b --> e > a > c|d > b|d
                        if (c > d){ // e > a > c > b|d
                            m = c;
                        }else{  // d >= c --> e > a > d > c > b
                            m = d;
                        }
                    }
                }
            }else{ // d >= a --> d|e > a|e > b|c|e
                if (d > e){ // d > a|e > b|c|e  ------------------------------------------------------d > a|b|c|e
                    h = d;
                    if (a > e){ // d > a > b|c|e
                        nh = a;
                        if (b > c){ // d > a > b|e > c|e
                            if (b > e){ // d > a > b > c|e
                                m = b;
                            }else{ // e >=b --> d > a > e > b > c
                                m = e;
                            }
                        }else{ // c >= b --> d > a > c|e > b|e
                            if (c > e) { // d > a > c > b|e
                                m = c;
                            }else{ // e >= c --> d > a > e > c > b
                                m = e;
                            }
                        }
                    }else{ // e >= a --> d > e > a > b|c 
                        nh = e;
                        m = a;
                    }
                }else{ // e >= d --> e > d > a > b|c -----------------------------------------------END d > a|b|c|e
                    h = e;
                    nh = d;
                    m = a;
                }
            }
        }else{ //c > a -- > c|d|e > a|d|e > b|d|e
            if (c > d){ // --> c|e > a|d|e > b|d|e
                if (c > e){// --> c > a|d|e > b|d|e
                    h = c; // -----------------------------------------------------------------------c > a|b|d|e
                    if (a > d){ // c > a|e > b|d|e
                        if (a > e){ // c > a > b|d|e
                            nh = a;
                            if (b > d){ //c > a > b|e > d|e
                                 if (b > e){ // c > a > b > d|e
                                     m = b;
                                 }else{ // c > a > e > b > d
                                     m = e;
                                 }
                            }else{ // d >= b --> c > a > d|e > b|e
                                if (d > e){ // c > a > d > b|e
                                     m = d;
                                }else{ // c > a > e > d > b
                                     m = e;
                                }
                            }
                        }else{ // e >= a --> c > e > a > b|d
                            nh = e;
                            m = a;
                        }
                    }else{ // d > a --> c > d|e > a|e > b|e
                        if (d > e){ //c > d > a|e > b|e
                            nh = d;
                            if (e > a){ // c > d > e > a > b
                                m = e;
                            }else{ //a >=e --> c > d > a > b|e
                                m = a;
                            }
                        }else{ // e > d --> c > e > d > a > b
                            nh = e;
                            m = d;
                        }
                    }// --------------------------------------------------------------------------END c > a|b|d|e
                }else{ // e >=c --> e > c > a|d > b|d
                     if (a > d){ // e > c > a > b|d
                         m = a;
                     }else{ // d >= a --> e > c > d > a > b
                         m = d;
                     }
                }
            }else{ // d >= c --> d > c|e > a|e > b|e
                if (c > e){ // d > c > a|e > b|e
                    if (a > e) { // d > c > a > b|e
                        m = a;
                    }else{ // e >= a --> d > c > e > a > b
                        m = e;
                    }
                }else{ // e >= c --> d > e > c > a > b
                    m = c;
                }
            }
        }
        
    }else{ // b >= a
        if (b > c){ // b > a|c 
            if (b > d){ //b > a|c|d
                if (b > e){ // b > a|c|d|e
                    h = b; // ------------------------------------------------------------------------b > a|c|d|e
                    if (a > c){ // b > a|d|e > c|d|e
                        if(a > d){ // b > a|e > c|d|e
                            if(a > e){ // b > a > c|d|e
                                nh = a; // ----------------------------- b > a > c|d|e
                                if( c > d){ // b > a > c|e > d|e
                                    if (c > e){ // b > a > c > d|e
                                        m = c;
                                    }else{ // e >= c --> b > a > e > c >d
                                        m = e;
                                    }
                                }else{// d >= c --> b > a > d|e > c|e
                                    if(d > e){ // b > a > d > c|e
                                        m = d;
                                    }else{ // e >= d --> b > a > e > d > c
                                        m = e;
                                    }
                                } // --------------------------------END b > a > c|d|e
                            }else{ // e >= a --> b > e > a > c|d
                                nh = e;
                                m = a;
                            }
                        }else{ // d >= a --> b > d|e > a|e > c|e
                            if (d > e){ // b > d > a|e > c|e
                                nh = d; // ------------------------- b > d > a|c|e
                                if(a > e){ // b > d > a > c|e
                                    m = a;
                                }else{ // e >=a --> b > d > e > a > c
                                    m = e;
                                }
                            }else{ // e >= d --> b > e > d > a > c
                                m = d;
                            }
                        } 
                    }else{ // c >= a --> b > c|d|e > a|d|e
                        if (c > d){ // b > c|e > a|d|e
                            if (c > e){ // b > c > a|d|e
                                nh = c; // -------------------------- b > c > a|d|e
                                if (a > d){ // b > c > a|e > d|e
                                    if (a > e){ // b > c > a > d|e
                                        m = a;
                                    }else{ // e >= a --> b > c > e > a > d
                                        m = e;
                                    }
                                }else{ // d >= a --> b > c > d|e > a|e
                                    if (d > e){ // b > c > d > a|e
                                        m = d;
                                    }else{ // e >= d --> b > c > e > d > a
                                        m = e;
                                    }
                                }// ------------------------------END b > c > a|d|e
                            }else{ // e >= c --> b > e > c > a|d
                                nh = e;
                                m = c;
                            }
                        }else{ // d >= c --> b > d|e > c|e > a|e
                            if (d > e){ // b > d > c|e > a|e
                                nh = d;// ---------------------
                                if (c > e){ // b > d > c > a|e
                                    m = c;
                                }else{ // e >= c --> b > d > e > c > a
                                    m = e;
                                }
                            }else{ // e >= d --> b > e > d > c > a
                                m = d;
                            }
                        }
                    } // -----------------------------------------------------------END b > a|c|d|e
                }else{ //e >=b --> e > b > a|c|d
                    if (a > c){ // e > b > a|d > c|d
                        if (a > d){ // e > b > a > c|d
                            m = a;
                        }else{ // d >= a --> e > b > d > a > c
                            m = d;
                        }
                    }else{ // c >= a --> e > b > c|d > a|d
                        if(c > d){ // e > b > c > a|d
                            m = c;
                        }else{ // d >= c --> e > b > d > c > a
                            m = c;
                        }
                    }
                }
            }else{ //d >= b --> d|e > b|e > a|c|e
                if (d > e){ // d > b|e > a|c|e
                    if (b > e){ // d > b > a|c|e
                        if (a > c){ // d > b > a|e > c|e
                            if(a > e){ // d > b > a > c|e
                                m = a;
                            }else{ // e >= a --> d > b > e > a > c
                                m = e;
                            }
                        }else{ // c >= a --> d > b > c|e > a|e
                            if (c > e){ // d > b > c > a|e
                                m = c;
                            }else{ // e >= c --> d > b > e > c > a
                                m = e;
                            }
                        }
                    }else{ // e >= b --> d > e > b > a|c
                        m = b;
                    }
                }else{ // e >= d --> e > d > b > a|c
                    m = b;
                }
            }
        }else{ //c >= b --> c|d|e > b|d|e > a|d|e
            if (c > d){ // c|e > b|d|e > a|d|e
                if (c > e){ // c > b|d|e > a|d|e
                    h = c;
                    if(b > d){ // c > b|e > a|d|e
                        if (b > e){ // c > b > a|d|e
                            if(a > d){ // c > b > a|e > d|e
                                if(a > e){ // c > b > a > d|e
                                    m = a;
                                }else{ // e >= a --> c > b > e > a > d
                                    m = e;
                                }
                            }else{ // d >= a --> c > b > d|e > a|e
                                if (d > e){ // c > b > d > a|e
                                    m = d;
                                }else{ // e >= d --> c > b > e > d > a
                                    m = e;
                                }
                            }
                        }else{ // e >= b --> c > e > b > a|d
                            m = b;
                        }
                    }else{ // d >= b --> c > d|e > b|e > a|e
                        if (d > e){ // c > d > b|e > a|e
                            if (b > e){ // c > d > b > a|e
                                m = b;
                            }else{ // e >= b --> c > d > e > b > a
                                m = e;
                            }
                        }else{ // e >= d --> c > e > d > b > a
                            m = d;
                        }
                    }
                }else{ // e >= c --> e > c > b|d > a|d
                    if (b > d){ // e > c > b > a|d
                        m = b;
                    }else{ // d >= b --> e > c > d > b > a
                        m = d;
                    }
                }
            }else{ // d >= c --> d|e > c|e > b|e > a|e
                if(d > e){ // d > c|e > b|e > a|e
                    if (c > e){ // d > c > b|e > a|e
                        if (b > e){ // d > c > b > a|e
                            m = b;
                        }else{ // e >= b --> d > c > e > b > a
                            m = e;
                        }
                    }else{ // e >= c --> d > e > c > b > a
                        m = c;
                    }
                }else{ // e >= d --> e > d > c > b > a
                    m = c;
                }
            }
        }
    }
    cout << "The median of the five integers is: " << m << endl;
}
