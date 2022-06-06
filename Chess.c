#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define I int
#define C char
#define V void
#define B bool
#define T true
#define F false

#define CO const
#define U unsigned

#define UI U I
#define UC U C
#define CUI CO UI
#define CUC CO UC

#define STR UC *
#define CSTR CUC *

#define LIST UI *
#define CLIST CUI *

LIST Table; enum {
    BLACK_PAWN = 1,
    BLACK_KNIGHT ,
    BLACK_BISHOP,
    BLACK_ROOK  ,
    BLACK_QUEEN ,
    BLACK_KING  ,

    WHITE_PAWN  ,
    WHITE_KNIGHT,
    WHITE_BISHOP,
    WHITE_ROOK  ,
    WHITE_QUEEN ,
    WHITE_KING  ,

    TOP_PAWN = 1 ,
    BOTTOM_PAWN = 6
};

typedef enum {
    BLACK,
    WHITE
} TEAM;

#define Escape(A, B) Table[A] = Table[B]; Table[B] = 0;
#define UpdateTable system("clear"); PrintTable();

V Reset(TEAM Bottom) {
    if (Bottom == BLACK) {
        // WHITE BOTTOM
        Table[0] = WHITE_ROOK;
        Table[1] = WHITE_KNIGHT;
        Table[2] = WHITE_BISHOP;
        Table[3] = WHITE_QUEEN;
        Table[4] = WHITE_KING;
        Table[5] = WHITE_BISHOP;
        Table[6] = WHITE_KNIGHT;
        Table[7] = WHITE_ROOK;
        // WHITE TOP
        Table[8] = WHITE_PAWN;
        Table[9] = WHITE_PAWN;
        Table[10] = WHITE_PAWN;
        Table[11] = WHITE_PAWN;
        Table[12] = WHITE_PAWN;
        Table[13] = WHITE_PAWN;
        Table[14] = WHITE_PAWN;
        Table[15] = WHITE_PAWN;

        // BLACK BOTTOM
        Table[56] = BLACK_ROOK;
        Table[57] = BLACK_KNIGHT;
        Table[58] = BLACK_BISHOP;
        Table[59] = BLACK_QUEEN;
        Table[60] = BLACK_KING;
        Table[61] = BLACK_BISHOP;
        Table[62] = BLACK_KNIGHT;
        Table[63] = BLACK_ROOK;
        // BLACK TOP
        Table[48] = BLACK_PAWN;
        Table[49] = BLACK_PAWN;
        Table[50] = BLACK_PAWN;
        Table[51] = BLACK_PAWN;
        Table[52] = BLACK_PAWN;
        Table[53] = BLACK_PAWN;
        Table[54] = BLACK_PAWN;
        Table[55] = BLACK_PAWN;
    } else {
        // BLACK BOTTOM
        Table[0] = BLACK_ROOK;
        Table[1] = BLACK_KNIGHT;
        Table[2] = BLACK_BISHOP;
        Table[3] = BLACK_QUEEN;
        Table[4] = BLACK_KING;
        Table[5] = BLACK_BISHOP;
        Table[6] = BLACK_KNIGHT;
        Table[7] = BLACK_ROOK;
        // BLACK TOP
        Table[8] = BLACK_PAWN;
        Table[9] = BLACK_PAWN;
        Table[10] = BLACK_PAWN;
        Table[11] = BLACK_PAWN;
        Table[12] = BLACK_PAWN;
        Table[13] = BLACK_PAWN;
        Table[14] = BLACK_PAWN;
        Table[15] = BLACK_PAWN;

        // WHITE BOTTOM
        Table[56] = WHITE_ROOK;
        Table[57] = WHITE_KNIGHT;
        Table[58] = WHITE_BISHOP;
        Table[59] = WHITE_QUEEN;
        Table[60] = WHITE_KING;
        Table[61] = WHITE_BISHOP;
        Table[62] = WHITE_KNIGHT;
        Table[63] = WHITE_ROOK;
        // WHITE TOP
        Table[48] = WHITE_PAWN;
        Table[49] = WHITE_PAWN;
        Table[50] = WHITE_PAWN;
        Table[51] = WHITE_PAWN;
        Table[52] = WHITE_PAWN;
        Table[53] = WHITE_PAWN;
        Table[54] = WHITE_PAWN;
        Table[55] = WHITE_PAWN;
    }
}

B Move(C *Pikachu, TEAM Team, TEAM BTeam) {
    UI Y1 = Pikachu[1], Y2 = Pikachu[3],
        X1 = Pikachu[0], X2 = Pikachu[2];
    if (Y1 < 49 | Y1 > 58) { system("clear");
        printf("Invalid Y coordinate in select!\n");
        return F;
    } else if (Y2 < 49 | Y2 > 58) { system("clear");
        printf("Invalid Y coordinate in move!\n");
        return F;
    } else {
        if (X1 < 97 | X1 > 104) { system("clear");
            printf("Invalid X coordinate in select!\n");
            return F;
        } else if (X2 < 97 | X2 > 104) { system("clear");
            printf("Invalid X coordinate in move!\n");
            return F;
        } else {
            Y1 -= 49; Y2 -= 49;
            X1 -= 97; X2 -= 97;
            if (Table[(Y1 * 8) + X1] < 7 & Team == WHITE) {
                system("clear");
                printf("WHITE are you colorblind?\n");
                return F;
            } else if (Table[(Y1 * 8) + X1] > 6 & Team == BLACK) {
                system("clear");
                printf("BLACK are you colorblind?\n");
                return F;
            } else {
                CUI Target = Table[(Y2 * 8) + X2];
                switch (Table[(Y1 * 8) + X1]) {
                    case (WHITE_PAWN): {
                        if (BTeam == WHITE) {    
                            if (Y1 == BOTTOM_PAWN) {
                                if (X2 != X1) {
                                    if ((X1 - X2) == 1 | (X2 - X1) == 1) {
                                        if (Y1 == BOTTOM_PAWN - 1) {
                                            if (Target != 0) {
                                                if (Target < 7) {
                                                    Escape((Y2 * 8) + X2, (Y1 * 8) + X1);
                                                    return T;
                                                } else { system("clear");
                                                    printf("WHITE pawn is allergic to white things!\n");
                                                    return F;
                                                }
                                            } else { system("clear");
                                                printf("WHITE pawn is allergic to nothing!\n");
                                                return F;
                                            }
                                        } else { system("clear");
                                            printf("WHITE pawn has allergic to go far!\n");
                                            return F;
                                        }
                                    } else { system("clear");
                                        printf("WHITE pawn has allergic to go far!\n");
                                        return F;
                                    }
                                } else {
                                    if (Y2 == BOTTOM_PAWN - 1) {
                                        if (Target == 0) {
                                            Escape((Y2 * 8) + X2, (Y1 * 8) + X1);
                                            return T;
                                        } else { system("clear");
                                            printf("WHITE pawn wants to stare front of something!\n");
                                            return F;
                                        }
                                    } else if (Y2 == BOTTOM_PAWN - 2) {
                                        if (Target == 0 & Table[(Y2 * 8) + X2] == 0) {
                                            Escape((Y2 * 8) + X2, (Y1 * 8) + X1);
                                            return T;
                                        } else { system("clear");
                                            printf("WHITE pawn wants to stare front of something!\n");
                                            return F;
                                        }
                                    } else { system("clear");
                                        printf("WHITE pawn don't want to go far away!\n");
                                        return F;
                                    }
                                }
                            } else {
                                if (X2 != X1) {
                                    if ((X1 - X2) == 1 | (X2 - X1) == 1) {
                                        if ((Y1 - Y2) == 1) {
                                            if (Target != 0) {
                                                if (Target < 7) {
                                                    Escape((Y2 * 8) + X2, (Y1 * 8) + X1);
                                                    return T;
                                                } else { system("clear");
                                                    printf("WHITE pawn is allergic to white things!\n");
                                                    return F;
                                                }
                                            } else { system("clear");
                                                printf("WHITE pawn is allergic to nothing!\n");
                                                return F;
                                            }
                                        } else { system("clear");
                                            printf("WHITE pawn has allergic to go far!\n");
                                            return F;
                                        }
                                    } else { system("clear");
                                        printf("WHITE pawn has allergic to go far!\n");
                                        return F;
                                    }
                                } else {
                                    if ((Y1 - Y2) == 1) {
                                        if (Target == 0) {
                                            Escape((Y2 * 8) + X2, (Y1 * 8) + X1);
                                            return T;
                                        } else { system("clear");
                                            printf("WHITE pawn wants to stare front of something!\n");
                                            return F;
                                        }
                                    } else { system("clear");
                                        printf("WHITE pawn don't want to go far away!\n");
                                        return F;
                                    }
                                }
                            }
                        } else {
                            if (Y1 == TOP_PAWN) {
                                if (X2 != X1) {
                                    if ((X1 - X2) == 1 | (X2 - X1) == 1) {
                                        if (Y1 == TOP_PAWN + 1) {
                                            if (Target != 0) {
                                                if (Target < 7) {
                                                    Escape((Y2 * 8) + X2, (Y1 * 8) + X1);
                                                    return T;
                                                } else { system("clear");
                                                    printf("WHITE pawn is allergic to white things!\n");
                                                    return F;
                                                }
                                            } else { system("clear");
                                                printf("WHITE pawn is allergic to nothing!\n");
                                                return F;
                                            }
                                        } else { system("clear");
                                            printf("WHITE pawn allergic to go far!\n");
                                            return F;
                                        }
                                    } else { system("clear");
                                        printf("WHITE pawn has allergic to go far!\n");
                                        return F;
                                    }
                                } else {
                                    if (Y2 == TOP_PAWN + 1) {
                                        if (Target == 0) {
                                            Escape((Y2 * 8) + X2, (Y1 * 8) + X1);
                                            return T;
                                        } else { system("clear");
                                            printf("WHITE pawn wants to stare front of something!\n");
                                            return F;
                                        }
                                    } else if (Y2 == TOP_PAWN + 2) {
                                        if (Target == 0 & Table[(Y2 * 8) + X2] == 0) {
                                            Escape((Y2 * 8) + X2, (Y1 * 8) + X1);
                                            return T;
                                        } else { system("clear");
                                            printf("WHITE pawn wants to stare front of something!\n");
                                            return F;
                                        }
                                    } else { system("clear");
                                        printf("WHITE pawn don't want to go far away!\n");
                                        return F;
                                    }
                                } 
                            } else {
                                if (X2 != X1) {
                                    if ((X1 - X2) == 1 | (X2 - X1) == 1) {
                                        if (Y1 == TOP_PAWN + 1) {
                                            if (Target != 0) {
                                                if (Target < 7) {
                                                    Escape((Y2 * 8) + X2, (Y1 * 8) + X1);
                                                    return T;
                                                } else { system("clear");
                                                    printf("WHITE pawn is allergic to white things!\n");
                                                    return F;
                                                }
                                            } else { system("clear");
                                                printf("WHITE pawn is allergic to nothing!\n");
                                                return F;
                                            }
                                        }
                                    } else { system("clear");
                                        printf("WHITE pawn has allergic to go far!\n");
                                        return F;
                                    }
                                } else {
                                    if (Y2 == TOP_PAWN + 1) {
                                        if (Target == 0) {
                                            Escape((Y2 * 8) + X2, (Y1 * 8) + X1);
                                            return T;
                                        } else { system("clear");
                                            printf("WHITE pawn wants to stare front of something!\n");
                                            return F;
                                        }
                                    } else { system("clear");
                                        printf("WHITE pawn don't want to go far away!\n");
                                        return F;
                                    }
                                }
                            }
                        } break;
                    } case (BLACK_PAWN): {
                        if (BTeam == BLACK) {    
                            if (Y1 == BOTTOM_PAWN) {
                                if (X2 != X1) {
                                    if ((X1 - X2) == 1 | (X2 - X1) == 1) {
                                        if (Y1 == BOTTOM_PAWN - 1) {
                                            if (Target != 0) {
                                                if (Target > 6) {
                                                    Escape((Y2 * 8) + X2, (Y1 * 8) + X1);
                                                    return T;
                                                } else { system("clear");
                                                    printf("BLACK pawn is allergic to black things!\n");
                                                    return F;
                                                }
                                            } else { system("clear");
                                                printf("BLACK pawn is allergic to nothing!\n");
                                                return F;
                                            }
                                        } else { system("clear");
                                            printf("BLACK pawn has allergic to go far!\n");
                                            return F;
                                        }
                                    } else { system("clear");
                                        printf("BLACK pawn has allergic to go far!\n");
                                        return F;
                                    }
                                } else {
                                    if (Y2 == BOTTOM_PAWN - 1) {
                                        if (Target == 0) {
                                            Escape((Y2 * 8) + X2, (Y1 * 8) + X1);
                                            return T;
                                        } else { system("clear");
                                            printf("BLACK pawn wants to stare front of something!\n");
                                            return F;
                                        }
                                    } else if (Y2 == BOTTOM_PAWN - 2) {
                                        if (Target == 0 & Table[(Y2 * 8) + X2] == 0) {
                                            Escape((Y2 * 8) + X2, (Y1 * 8) + X1);
                                            return T;
                                        } else { system("clear");
                                            printf("BLACK pawn wants to stare front of something!\n");
                                            return F;
                                        }
                                    } else { system("clear");
                                        printf("BLACK pawn don't want to go far away!\n");
                                        return F;
                                    }
                                }
                            } else {
                                if (X2 != X1) {
                                    if ((X1 - X2) == 1 | (X2 - X1) == 1) {
                                        if ((Y1 - Y2) == 1) {
                                            if (Target != 0) {
                                                if (Target > 6) {
                                                    Escape((Y2 * 8) + X2, (Y1 * 8) + X1);
                                                    return T;
                                                } else { system("clear");
                                                    printf("BLACK pawn is allergic to black things!\n");
                                                    return F;
                                                }
                                            } else { system("clear");
                                                printf("BLACK pawn is allergic to nothing!\n");
                                                return F;
                                            }
                                        } else { system("clear");
                                            printf("BLACK pawn has allergic to go far!\n");
                                            return F;
                                        }
                                    } else { system("clear");
                                        printf("BLACK pawn has allergic to go far!\n");
                                        return F;
                                    }
                                } else {
                                    if ((Y1 - Y2) == 1) {
                                        if (Target == 0) {
                                            Escape((Y2 * 8) + X2, (Y1 * 8) + X1);
                                            return T;
                                        } else { system("clear");
                                            printf("BLACK pawn wants to stare front of something!\n");
                                            return F;
                                        }
                                    } else { system("clear");
                                        printf("BLACK pawn don't want to go far away!\n");
                                        return F;
                                    }
                                }
                            }
                        } else {
                            if (Y1 == TOP_PAWN) {
                                if (X2 != X1) {
                                    if ((X1 - X2) == 1 | (X2 - X1) == 1) {
                                        if (Y1 == TOP_PAWN + 1) {
                                            if (Target != 0) {
                                                if (Target > 6) {
                                                    Escape((Y2 * 8) + X2, (Y1 * 8) + X1);
                                                    return T;
                                                } else { system("clear");
                                                    printf("BLACK pawn is allergic to black things!\n");
                                                    return F;
                                                }
                                            } else { system("clear");
                                                printf("BLACK pawn is allergic to nothing!\n");
                                                return F;
                                            }
                                        } else { system("clear");
                                            printf("BLACK pawn allergic to go far!\n");
                                            return F;
                                        }
                                    } else { system("clear");
                                        printf("BLACK pawn has allergic to go far!\n");
                                        return F;
                                    }
                                } else {
                                    if (Y2 == TOP_PAWN + 1) {
                                        if (Target == 0) {
                                            Escape((Y2 * 8) + X2, (Y1 * 8) + X1);
                                            return T;
                                        } else { system("clear");
                                            printf("BLACK pawn wants to stare front of something!\n");
                                            return F;
                                        }
                                    } else if (Y2 == TOP_PAWN + 2) {
                                        if (Target == 0 & Table[(Y2 * 8) + X2] == 0) {
                                            Escape((Y2 * 8) + X2, (Y1 * 8) + X1);
                                            return T;
                                        } else { system("clear");
                                            printf("BLACK pawn wants to stare front of something!\n");
                                            return F;
                                        }
                                    } else { system("clear");
                                        printf("BLACK pawn don't want to go far away!\n");
                                        return F;
                                    }
                                } 
                            } else {
                                if (X2 != X1) {
                                    if ((X1 - X2) == 1 | (X2 - X1) == 1) {
                                        if (Y1 == TOP_PAWN + 1) {
                                            if (Target != 0) {
                                                if (Target > 6) {
                                                    Escape((Y2 * 8) + X2, (Y1 * 8) + X1);
                                                    return T;
                                                } else { system("clear");
                                                    printf("BLACK pawn is allergic to black things!\n");
                                                    return F;
                                                }
                                            } else { system("clear");
                                                printf("BLACK pawn is allergic to nothing!\n");
                                                return F;
                                            }
                                        }
                                    } else { system("clear");
                                        printf("BLACK pawn has allergic to go far!\n");
                                        return F;
                                    }
                                } else {
                                    if (Y2 == TOP_PAWN + 1) {
                                        if (Target == 0) {
                                            Escape((Y2 * 8) + X2, (Y1 * 8) + X1);
                                            return T;
                                        } else { system("clear");
                                            printf("BLACK pawn wants to stare front of something!\n");
                                            return F;
                                        }
                                    } else { system("clear");
                                        printf("BLACK pawn don't want to go far away!\n");
                                        return F;
                                    }
                                }
                            }
                        } break;
                    } default: {
                        Escape((Y2 * 8) + X2, (Y1 * 8) + X1);
                        return T;
                    }
                }
                // Table[(Y2 * 8) + X2] = Table[(Y1 * 8) + X1];
                // Table[(Y1 * 8) + X1] = 0;
            }
            return T;
        }
    }
}

V PrintTable() { UI Idx = 0;
    printf("\n   ┅┅  ┅┅  ┅┅  ┅┅  ┅┅ ┅┅  ┅┅  ┅┅\n  ");
    for (UI Y = 0; Y < 8; Y++) {
        for (UI X = 0; X < 8; X++) {
            switch (Table[Idx]) {
                case (BLACK_PAWN): {
                    printf("┇♟ ┇");
                    break;
                } case (WHITE_PAWN): {
                    printf("┇♙ ┇");
                    break;
                } case (BLACK_KNIGHT): {
                    printf("┇♘ ┇");
                    break;
                } case (WHITE_KNIGHT): {
                    printf("┇♞ ┇");
                    break;
                } case (BLACK_BISHOP): {
                    printf("┇♗ ┇");
                    break;
                } case (WHITE_BISHOP): {
                    printf("┇♝ ┇");
                    break;
                } case (BLACK_ROOK): {
                    printf("┇♖ ┇");
                    break;
                } case (WHITE_ROOK): {
                    printf("┇♜ ┇");
                    break;
                } case (BLACK_QUEEN): {
                    printf("┇♕ ┇");
                    break;
                } case (WHITE_QUEEN): {
                    printf("┇♛ ┇");
                    break;
                } case (BLACK_KING): {
                    printf("┇♔ ┇");
                    break;
                } case (WHITE_KING): {
                    printf("┇♚ ┇");
                    break;
                } default: {
                    printf("┇  ┇");
                }
            }
            Idx++;
        }
        printf("\n%i ┇┅┅  ┅┅  ┅┅  ┅┅  ┅┅  ┅┅  ┅┅  ┅┅┇\n  ", Y + 1);
    } printf(" a   b   c   d   e   f   g   h\n");
}

I main(V) {
    Table = (LIST) calloc (
        64, sizeof(UI)
    ); C Answer, _Move[5];

    system("clear");
    TEAM BTeam,
    CurrTeam = WHITE;

    while (1) {
        printf("(P) Play or (Q) Quit?\n");
        scanf("%c", &Answer);
        if (Answer == 'P') {
            system("clear");
            while (1) {
                printf("What team bottom should be?\n");
                scanf("%c", &Answer);
                scanf("%c", &Answer);
                if (Answer == 'W') {
                    Reset(WHITE);
                    BTeam = WHITE;
                    break;
                } else if (Answer == 'B') {
                    Reset(BLACK);
                    BTeam = BLACK;
                    break;
                } else {
                    printf("Answer must be (W) White or (B) Black!\n");
                }
            } UpdateTable while (1) {
                if (CurrTeam == WHITE) {
                    printf("WHITE: ");
                } else {
                    printf("BLACK: ");
                }

                scanf("%s %s", &_Move[0], &_Move[2]);
                B Legal = Move(_Move, CurrTeam, BTeam);

                if (Legal == F) {
                    PrintTable();
                } else {
                    UpdateTable
                    if (CurrTeam == WHITE) {
                        CurrTeam = BLACK;
                    } else {
                        CurrTeam = WHITE;
                    }
                }
            }
        } else if (Answer == 'Q') {
            system("clear");
            break;
        } else {
             printf("(P) Play or (Q) Quit?\n");
        }
    }
    free(Table);
}