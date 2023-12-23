# 基础知识

## 约数

如果数 $a$ 能被数 $b$ 整除， $a$ 就叫做 $b$ 的倍数， $b$ 就叫做 $a$ 的约数。约数和倍数都表示一个整数与另一个整数的关系，不能单独存在。

## 质因数

就是一个数的约数，并且是质数。

## 互质

若N个整数的最大公因数是 $1$ ，则称这 $N$ 个整数互质。

## 公约数

定义：如果 d|a（d 整除 a）且 d|b，那么 d 是 a 与 b 的 公约数。
性质：如果 d|a 且 d|b，那么 d|(ax + by); x,y ∈ Z(任意整数)

## 最大公约数

1. 定义：两个非零整数 $a$ 和 $b$ 的公约数里最大的就是 最大公约数。

2. 相关等式跟推论：
   * 等式 1：如果 a|b 且 b|a 那么 a = $\pm$ b
   * 等式 2：如果 d|a 且 d|b 那么 d|(ax + by); (x,y) $\in$ Z
   * 等式 3：a%n = a-n $\lfloor$ a/n $\rfloor$ (向下整除); a $\in$ Z,n $\in N^\star$ (正整数)
   * 推论 1：对任意整数a,b，如果 d|a 且 d|b 则 d| $gcd(a, b)$

3. 求法
   1. 质因数分解法

      把每个数分别分解质因数，再把各数中的全部公有质因数提取出来连乘，所得的积就是这几个数的最大公约数。
   2. 短除法

      先用这几个数的公约数连续去除，一直除到所有的商互质为止，
    然后把所有的除数连乘起来，所得的积就是这几个数的最大公约数。
   3. 辗转相除法（欧几里德算法）
      * 定理：两个整数的最大公约数等于其中较小的那个数和两数相除余数的最大公约数。
      * 过程：以除数和余数反复做除法运算，当余数为 0 时，取当前算式除数为最大公约数。
      为了证明这个定理，我们首先需要知道一下有关 gcd 的基本知识跟相关等式跟推论。
        * 基础知识

          欧几里得算法的原理是 $GCD$ 递归定理：对任意非负整数a和任意整数b， $gcd(a,b) = gcd(b,a \bmod b)$
        * 证明过程

        * 要获得结论 $gcd(a,b) = gcd(b, a \bmod b)$

          利用最大公约数中的等式1证明 $gcd(a,b) | gcd(b, a \bmod b)$ 且 $gcd(b,a \bmod b) | gcd(a,b)$ 。
          1. 证明 $gcd(a,b) | gcd(b,a \bmod b)$

             设 $d = gcd(a, b)$

             $\therefore d | a$ 且 $d | b$

             $\because$ 由等式3可知： $(a \bmod b) = a -  q\times b\quad (q = \lfloor a/b\rfloor)$

             $\therefore a \bmod b$ 是 $a$ 与 $b$ 的线性组合

             $\therefore$ 由等式2可知： $d | (a \bmod b)$

             $\because d | b$ 且 $d | (a \bmod b)$
             $\therefore$ 由推论1可知： $d|gcd(b, a \bmod b)$
             等价结论： $gcd(a, b) | gcd(b, a \bmod b)$

          2. 证明 $gcd(b,a \bmod b)|gcd(a,b)$

             设 $c = gcd(b, a \bmod b)$

             $\therefore c|b$ 且 $c|(a \bmod b)$

             $\because a = q\times b + r\quad (r = a \bmod b,\quad q = ⌊a/b⌋)$

             $\therefore a$ 是 $b$ 和 $(a \bmod b)$ 的线性组合

             $\therefore$ 由等式2可知： $c|a$

             $\because c|a$ 且 $c|b$

             $\therefore$ 由推论1可知： $c|gcd(a, b)$

             等价结论： $gcd(b, a \bmod b)|gcd(a, b)$

          3. 证明 $gcd(a,b) = gcd(b, a \bmod b)$

             由上述两个结论可知：
             $gcd(a, b)|gcd(b, a \bmod b)\bigcup gcd(b, a \bmod b)|gcd(a, b)$  
             $\therefore$ 由等式1可知： $gcd(a, b) = gcd(b, a \bmod b)$  

          证明结束
4. 更相减损法（等值算法）：
   1. 任意给定两个正整数；判断它们是否都是偶数。若是，则用2约简；若不是则执行第二步。
   2. 以较大的数减较小的数，接着把所得的差与较小的数比较，并以大数减小数。继续这个操作，直到所得的减数和差相等为止。
   3. 则第一步中约掉的若干个2与第二步中等数的乘积就是所求的最大公约数。  
   4. 其中所说的“等数”，就是最大公约数。  
   5. 求“等数”的办法是“更相减损”法。所以更相减损法也叫等值算法。

## 最小公倍数

几个数共有的倍数叫做这几个数的公倍数，其中除 $0$ 以外最小的一个公倍数，叫做这几个数的最小公倍数。

### 计算方法

1. 分解质因数法:

   先把这几个数的质因数写出来，最小公倍数等于它们所有的质因数的乘积,（如果有几个质因数相同，则比较几个数中哪个数有该质因数的个数较多，乘较多的次数）。
2. 公式法:

   两个数的乘积等于这两个数的最大公约数与最小公倍数的积。

   证明 $(a,b)\times [a,b]=ab，\quad(a,b)$ 表示 $a$ , $b$ 的最大公约数， $[a,b]$表示 $a$, $b$ 的最小公倍数
    * 方法1  
      $a,b$ 的公倍数都是 $[a,b]$ 的倍数。

      要证明 $(a,b)\times [a,b]=ab$，

      只要证明 $(a,b)\times [a,b]\geqslant ab$···①

      且 $(a,b)\times [a,b] \leqslant ab$···②

      ①式等价于 $[a,b]\geqslant ab/(a,b)$

      则①式右值为 $a$ 和 $b$ 的公倍数，

      则大于等于最小公倍数，得证。

      ②式等价于 $(a,b)\geqslant ab/[a,b]$

      设 $m=[a,b]/b$

      则②式右值为 $a/m$ ，为 $a$ 的约数

      同理右值也为 $b$ 的约数

      所以②式右值小于等最大公约数

      得证。
    * 方法2  
      设 $(a,b)=k$
      则 $a=m\times k$ , $b=n\times k\quad$ ( $mn$ 互质)
      则 $[a,b]=m×n×k$
      所以 $ab=mnk^2，(a,b)\times [a,b]=mnk^2$,
      得证。

## 切线

1. 定义

   曲线 $C$ 为函数 $y=f(x)$ 的图形的情形，设点 $A(x_0,y_0)$ 是曲线 $C$ 上一点， $B(x,y)$ 为另一点，作割线 $AB$ ，

   割线 $AB$ 的斜率为 $$\tan\beta=\frac{y-y_0}{x-x_0}=\frac{f(x)-f(x_0)}{x-x_0}$$ $\beta$ 是割线 $AB$ 的倾角

   当点 $B$ 沿曲线 $C$ 运动趋于点 $A$ ， $x$ 趋于 $x_0$,若当 $x\to x_0$ 时，极限存在，设为 $k$ ， $$k=\lim\limits_{x\rightarrow x_0}\dfrac{f(x)-f(x_0)}{x-x_0}$$

   即 $k$ 是割线 $AB$ 斜率的极限，也就是切线 $AT$ 的斜率，这里 $k=\tan\alpha$，$\alpha$ 为切线 $AT$ 的倾角。

   因此过点 $A$ 且以 $k$ 为斜率的直线 $AT$ 就是曲线 $C$ 在点 $A$ 处的切线，简称切线是曲线的线性逼近。

## 导数

$$
k=\lim\limits_{x\rightarrow x_0}\dfrac{f(x)-f(x_0)}{x-x_0}
=\lim\limits_{\Delta x\rightarrow 0}\dfrac{\Delta y}{\Delta x}
=\lim\limits_{\Delta x\rightarrow 0}\dfrac{f(x_0+\Delta x)-f(x_0)}{\Delta x}
$$
我们把此极限成为导数。

1. 函数在一点处的导数
   * 定义  
     设函数 $y=f(x)$ 在点 $x_0$ 的某个邻域内有定义，

     当自变量 $x$ 在 $x_0$ 处取得增量 $\Delta x$ ($x_0+\Delta x$仍然在该邻域内)时，

     因变量 $y$ 相应的取得增量 $\Delta y=f(x_0+\Delta x)-f(x_0)$,

     若 $\lim\limits_{\Delta x\rightarrow 0}\dfrac{ \Delta y}{\Delta x}$ 存在，

     则称函数 $y=f(x)$ 在点 $x_0$ 处可导，

     并称该极限为函数 $y=f(x)$ 在点 $x_0$ 处导数，

     记为 $f'(x_0)$,

     则有 $$f'(x_0)=\lim\limits_{\Delta x\rightarrow 0}\dfrac{ \Delta y}{\Delta x}=\lim\limits_{\Delta x\rightarrow 0}\dfrac{f(x_0+\Delta x)-f(x_0)}{\Delta x}$$

     也可记作 $y'|x=x_0$ , $\frac{dy}{dx}|x=x_0$ 或 $y'=\frac{df(x)}{dx}|x=x_0$

### 求切线方程

设平面曲线 $C：y=f(x)$ ，点 $A(x_0,y_0)$ 是曲线 $y=f(x)$ 上的一点，

且函数 $y=f(x)$在 $x_0$ 处可导，

则 $y=f(x)$ 在点 $A$ 处的切线斜率： $$k=\tan\alpha=\lim\limits_{\Delta x\rightarrow 0}\dfrac{f(x_0)+\Delta x}{\Delta x}=f'(x_0)$$

由直线的点斜式方程 $y-y_0=k\times(x-x_0)$ 可以得到切线方程： $y-f(x_0)=f'(x_0)(x-x_0)$ ,即 $y=f(x_0)+f'(x_0)(x-x_0)$ 。

### 求平面曲线C：y=f(x)上点A(x_0,y0)的切线与x轴的交点横坐标

即求切线方程 $f(x_0)+f'(x_0)(x-x_0)=0$ 的解

得 $x=x_0-f(x)/'f(x_0)$

## 迭代法

迭代法是一种逐次逼近法，是一种不断用变量的旧值递推新值的过程。

基本思想：

首先给定方程的一个粗糙的初始近似根,

然后用一个固定公式反复校正这个根的近似值使之逐步精确化,

直到满足预先给定的精度要求为止。

### 迭代法求 $x=\sqrt a$

即 $x^2-a=0$ 的解。

设平面曲线 $C：y=f(x)=x^2-a$ ，取平面曲线 $C$ 上任意点 $A(x_n,f(x_n))$，

过点 $A$ 作曲线 $C$ 的切线 $AT$ ，得切线方程为 $y=f(x_n)+f'(x_n)(x-x_n)$，

则切线 $AT$与 $x$ 轴的交点横坐标，即切线的根 $x_{n+1}=x_n-\frac{f(x_n)}{f'(x_n)}$,

即 $$x_{n+1}=x_n-\frac{x_n^2-a}{2\times x_n}=\frac12\times \frac{x_n^2+a}{x_n}$$

不断的执行上述步骤，可以发现 $x_{n+1}$ 不断的趋于 $y=0$ 的 $x$ 的点，

当 $x_n$ 与 $x_{n+1}$ 的差的绝对值大于或等于某个精度时，认为此时的 $x{n+1}$ 是方程 $f(x)=0$ 的解。

上式 $$\frac12\times \frac{x_n^2+a}{x_n}$$ 为求平方根的迭代公式,记为 $g(x)$。

算法可按以下步骤执行

1. 选一个方程的近似根，赋给变量 $x_0$ ；
2. 将 $x_0$ 的值保存于变量 $x_1$，然后计算 $g(x_1)$，并将结果存于变量 $x_0$ ；
3. 当 $x_0$ 与 $x_1$ 的差的绝对值还小于指定的精度要求时，重复步骤 $2$ 的计算。
若方程有根，并且用上述方法计算出来的近似根序列收敛，则按上述方法求得的 $x_0$ 就认为是方程的根。
