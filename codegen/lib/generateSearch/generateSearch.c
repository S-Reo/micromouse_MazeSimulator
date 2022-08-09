/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: generateSearch.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 10-Aug-2022 00:12:05
 */

/* Include Files */
#include "generateSearch.h"
#include "generateSearch_data.h"
#include "generateSearch_initialize.h"
#include <math.h>

/* Function Definitions */
/*
 * 次の目標座標までの経路配列を返す
 * 経路サンプル
 * x = [1; 2;5];
 * y = [3; 4;6];
 * route = [x y];
 *     %%
 *
 * Arguments    : unsigned char x
 *                unsigned char y
 *                unsigned char car
 *                unsigned char route[2]
 * Return Type  : void
 */
void generateSearch(unsigned char x, unsigned char y, unsigned char car,
                    unsigned char route[2])
{
  float myM_tmp;
  int b_q;
  unsigned int b_x;
  int dec;
  unsigned int q;
  unsigned char b_y;
  unsigned char c_tmp;
  unsigned char c_x;
  unsigned char d;
  signed char now_wall_idx_0;
  signed char now_wall_idx_1;
  signed char now_wall_idx_2;
  signed char now_wall_idx_3;
  signed char w_idx_0;
  signed char w_idx_1;
  signed char w_idx_2;
  signed char w_idx_3;
  if (!isInitialized_generateSearch) {
    generateSearch_initialize();
  }
  /* car = 0; %北 */
  /* x = 1; */
  /* y = 2; */
  /* route = generateSearc(x,y,car); */
  /* 引数は、新しい区画に入った時の座標と、方角 */
  /* disp("壁情報, デバッグ"); %1の32の壁は1101じゃないといけない 向き確認、 */
  /* 今いる座標の（0から15）を取得 */
  myM_tmp = M[(x + ((y - 1) << 5)) - 1];
  myM[(x + ((y - 1) << 4)) - 1] = myM_tmp;
  /* disp(M(x,y)); %9になってる */
  /* 今いる座標の壁の有無を表す1×4行列に変換 */
  /* disp("(=_=)"); */
  /* tic */
  myM_tmp = roundf(myM_tmp);
  if (myM_tmp < 32768.0F) {
    if (myM_tmp >= -32768.0F) {
      dec = (int)myM_tmp;
    } else {
      dec = MIN_int16_T;
    }
  } else if (myM_tmp >= 32768.0F) {
    dec = MAX_int16_T;
  } else {
    dec = 0;
  }
  /* 0.006480 */
  /* toc */
  /* disp(); */
  /* debug = [x y]; */
  /* disp(debug); */
  /* debug2 = [q r]; */
  /* disp(debug2); */
  if (dec >= 0) {
    b_x = (unsigned int)dec;
  } else if (dec == MIN_int16_T) {
    b_x = 32768U;
  } else {
    b_x = (unsigned int)-dec;
  }
  q = b_x >> 3;
  b_x -= q << 3;
  if (b_x >= 4U) {
    q++;
  }
  b_q = (int)q;
  if (dec < 0) {
    b_q = -(int)q;
  }
  if (b_q != 0) {
    now_wall_idx_3 = 1;
    if (dec < -32760) {
      dec = MIN_int16_T;
    } else {
      dec -= 8;
    }
  } else {
    now_wall_idx_3 = 0;
  }
  /* 0.001470 →0.000783 */
  if (dec >= 0) {
    b_x = (unsigned int)dec;
  } else if (dec == MIN_int16_T) {
    b_x = 32768U;
  } else {
    b_x = (unsigned int)-dec;
  }
  q = b_x >> 2;
  b_x -= q << 2;
  if (b_x >= 2U) {
    q++;
  }
  b_q = (int)q;
  if (dec < 0) {
    b_q = -(int)q;
  }
  /* debug2 = [q r]; */
  /* disp(debug2); */
  if (b_q != 0) {
    now_wall_idx_2 = 1;
    if (dec < -32764) {
      dec = MIN_int16_T;
    } else {
      dec -= 4;
    }
  } else {
    now_wall_idx_2 = 0;
  }
  if (dec >= 0) {
    b_x = (unsigned int)dec;
  } else if (dec == MIN_int16_T) {
    b_x = 32768U;
  } else {
    b_x = (unsigned int)-dec;
  }
  q = b_x >> 1;
  b_x -= q << 1;
  if (b_x > 0U) {
    q++;
  }
  b_q = (int)q;
  if (dec < 0) {
    b_q = -(int)q;
  }
  /* debug2 = [q r]; */
  /* disp(debug2); */
  if (b_q != 0) {
    now_wall_idx_1 = 1;
    if (dec < -32766) {
      dec = MIN_int16_T;
    } else {
      dec -= 2;
    }
  } else {
    now_wall_idx_1 = 0;
  }
  /* debug2 = [q r]; */
  /* disp(debug2); */
  now_wall_idx_0 = (signed char)(dec != 0);
  /* disp(bit); */
  /* disp(nn); */
  /* disp(now_wall); */
  /* 1×4行列と今の方角から前後左右の壁の情報を取得 */
  /* { */
  /* function nn = M16toW4nn(x,y) */
  /*      */
  /*     %disp("(=_=)"); */
  /*      */
  /*     global M  */
  /*     %tic */
  /*     bit = zeros(1, 4); */
  /*     dec = sym(M(x,y)); */
  /*     q = 1; */
  /*      */
  /*     %{ */
  /*     先にsym宣言した場合 */
  /*     経過時間は 0.000124 秒です。宣言の処理 */
  /*     経過時間は 0.005934 秒です。quoremの処理 */
  /*     %} */
  /*     %{ */
  /*     quorem内で変換した場合 */
  /*     経過時間は 0.005820 秒です。 */
  /*     %} */
  /*     %tic */
  /*      */
  /*     [q, r]=quorem(dec,sym(8)); %西 */
  /*     %0.006480 */
  /*     %toc */
  /*     %disp(); */
  /*     %debug = [x y]; */
  /*     %disp(debug); */
  /*     %debug2 = [q r]; */
  /*     %disp(debug2); */
  /*     if  q */
  /*         bit(1,4) = 1; */
  /*         dec = dec - 8; */
  /*         if r == 0 */
  /*             bit(1,1) = 0; */
  /*             bit(1,2) = 0; */
  /*             bit(1,3) = 0; */
  /*             nn = bit; */
  /*             return */
  /*         end */
  /*     else */
  /*         bit(1,4) = 0; */
  /*     end%0.001470 →0.000783 */
  /*     [q, r]=quorem(dec,sym(4));%南 */
  /*     %debug2 = [q r]; */
  /*     %disp(debug2); */
  /*     if q */
  /*         bit(1,3) = 1; */
  /*         dec = dec - 4; */
  /*         if r == 0 */
  /*             bit(1,1) = 0; */
  /*             bit(1,2) = 0; */
  /*             %bit(1,4) = 0; */
  /*             nn = bit; */
  /*             return */
  /*         end */
  /*     else */
  /*         bit(1,3) = 0; */
  /*     end */
  /*      */
  /*     [q, r]=quorem(dec,sym(2)); */
  /*     %debug2 = [q r]; */
  /*     %disp(debug2); */
  /*     if q */
  /*         bit(1,2) = 1; */
  /*         dec = dec - 2; */
  /*         if r == 0 */
  /*             bit(1,1) = 0; */
  /*             %bit(1,3) = 0; */
  /*             %bit(1,4) = 0; */
  /*             nn = bit; */
  /*             return */
  /*         end */
  /*     else */
  /*         bit(1,2) = 0; */
  /*     end */
  /*  */
  /*     [q]=quorem(dec,sym(1)); */
  /*     %debug2 = [q r]; */
  /*     %disp(debug2); */
  /*     if q */
  /*         bit(1,1) = 1; */
  /*     else */
  /*         bit(1,1) = 0; */
  /*     end */
  /*     %disp(bit); */
  /*      */
  /*     nn = bit; */
  /*     %disp(nn); */
  /*      */
  /* end */
  /* } */
  w_idx_0 = 0;
  w_idx_1 = 0;
  w_idx_2 = 0;
  w_idx_3 = 0;
  c_tmp = (unsigned char)(car % 4);
  if (c_tmp == 0) {
    /* 北 */
    if (now_wall_idx_0 == 1) {
      w_idx_0 = 1;
    }
    if (now_wall_idx_1 == 1) {
      w_idx_1 = 1;
    }
    if (now_wall_idx_2 == 1) {
      w_idx_2 = 1;
    }
    if (now_wall_idx_3 == 1) {
      w_idx_3 = 1;
    }
  } else if (c_tmp == 1) {
    /* 東 */
    if (now_wall_idx_0 == 1) {
      /* 北 */
      w_idx_3 = 1;
      /* 左 */
    }
    if (now_wall_idx_1 == 1) {
      /* 東 */
      w_idx_0 = 1;
      /* 前 */
    }
    if (now_wall_idx_2 == 1) {
      /* 南 */
      w_idx_1 = 1;
      /* 右 */
    }
    if (now_wall_idx_3 == 1) {
      /* 西 */
      w_idx_2 = 1;
      /* 後ろ */
    }
  } else if (c_tmp == 2) {
    /* 南 */
    if (now_wall_idx_0 == 1) {
      w_idx_2 = 1;
    }
    if (now_wall_idx_1 == 1) {
      w_idx_3 = 1;
    }
    if (now_wall_idx_2 == 1) {
      w_idx_0 = 1;
    }
    if (now_wall_idx_3 == 1) {
      w_idx_1 = 1;
    }
  } else {
    /* 西向き */
    if (now_wall_idx_0 == 1) {
      /* 北 */
      w_idx_1 = 1;
      /* 右 */
    }
    if (now_wall_idx_1 == 1) {
      /* 東 */
      w_idx_2 = 1;
      /* 後ろ */
    }
    if (now_wall_idx_2 == 1) {
      /* 南 */
      w_idx_3 = 1;
      /* 左 */
    }
    if (now_wall_idx_3 == 1) {
      /* 西 */
      w_idx_0 = 1;
      /* 後ろ */
    }
  }
  /* 右 */
  /* 16の数値を1×4行列に直す関数を呼ぶ */
  /* 前後左右の壁の情報から進行方向を決定 */
  /* disp(w); */
  /* 元の方角と進行方向から座標を更新 */
  /* ここまで0.04秒くらい */
  d = 0U;
  if (w_idx_3 == 0) {
    /* 左|| */
    d = 3U;
  } else if (w_idx_0 != 0) {
    if (w_idx_1 == 0) {
      /* 右 */
      d = 1U;
    } else if (w_idx_2 == 0) {
      /* 後 */
      d = 2U;
    }
  } else {
    /* 前 8,10 */
    /* h = viscircles(ax,[x*0.5 y*0.5],0.3); */
  }
  /* ここは0.000004くらい */
  c_x = x;
  b_y = y;
  /* 現在の方角と、選んだ進行方向から、xyを更新 */
  d = (unsigned char)(d % 4);
  /* disp("c car d dir X Y") */
  /* debug = zeros(1,6); */
  /* debug = [c car d dir x y]; */
  /* disp(debug); */
  if (c_tmp == 0) {
    /* 北 */
    if (d == 0) {
      b_y = (unsigned char)(y + 1);
    } else if (d == 1) {
      c_x = (unsigned char)(x + 1);
    } else if (d == 2) {
      b_y = (unsigned char)(y - 1);
    } else {
      c_x = (unsigned char)(x - 1);
    }
  } else if (c_tmp == 1) {
    /* 東 */
    if (d == 0) {
      c_x = (unsigned char)(x + 1);
    } else if (d == 1) {
      b_y = (unsigned char)(y - 1);
    } else if (d == 2) {
      c_x = (unsigned char)(x - 1);
    } else {
      b_y = (unsigned char)(y + 1);
    }
  } else if (c_tmp == 2) {
    /* 南 */
    if (d == 0) {
      b_y = (unsigned char)(y - 1);
    } else if (d == 1) {
      c_x = (unsigned char)(x - 1);
    } else if (d == 2) {
      b_y = (unsigned char)(y + 1);
    } else {
      c_x = (unsigned char)(x + 1);
    }

    /* 西 */
  } else if (d == 0) {
    c_x = (unsigned char)(x - 1);
  } else if (d == 1) {
    b_y = (unsigned char)(y + 1);
  } else if (d == 2) {
    c_x = (unsigned char)(x + 1);
  } else {
    b_y = (unsigned char)(y - 1);
  }
  /* disp(x); */
  /* disp(y); */
  route[0] = c_x;
  route[1] = b_y;
  /* setXY(x,y); */
  /*  移動した方向と現在の方角から新しい方角に変更 */
  /* car = changecardinal(dir); */
}

/*
 * File trailer for generateSearch.c
 *
 * [EOF]
 */
