using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class X
{
    struct Z : IComparable<Z>
    {
        public long a;
        public int b;
        public int c;

        public Z(long x, int y, int z)
        {
            a = x;
            b = y;
            c = z;
        }

        public int CompareTo(Z x)
        {
            return a.CompareTo(x.a);
        }
    }

    static void Main()
    {
        A();
    }

    static void A()
    {
        string[] x = Console.In.ReadToEnd().Split(new[] { ' ', '\n', '\r', '\t' }, StringSplitOptions.RemoveEmptyEntries);
        int a = 0;
        int b = int.Parse(x[a++]);
        var c = new List<string>();

        for (int d = 0; d < b; d++)
        {
            int e = int.Parse(x[a++]);
            int f = int.Parse(x[a++]);
            int g = int.Parse(x[a++]);
            
            int h = int.Parse(x[a++]);
            var i = new List<int>[e + 1];
            for (int j = 0; j <= e; j++)
                i[j] = new List<int>();

            for (int j = 0; j < h; j++)
            {
                int k = int.Parse(x[a++]);
                int l = int.Parse(x[a++]);
                i[k].Add(l);
                i[l].Add(k);
            }

            int m = int.Parse(x[a++]);
            var n = new List<int>[e + 1];
            for (int j = 0; j <= e; j++)
                n[j] = new List<int>();

            for (int j = 0; j < m; j++)
            {
                int k = int.Parse(x[a++]);
                int l = int.Parse(x[a++]);
                n[k].Add(l);
                n[l].Add(k);
            }

            var o = new bool[e + 1];
            for (int j = 1; j <= e; j++)
            {
                var p = new HashSet<int>(n[j]);
                foreach (var q in i[j])
                {
                    if (p.Contains(q))
                    {
                        o[j] = true;
                        break;
                    }
                }
            }

            const long r = 1000000000000000000L;
            var s = new long[e + 1, e + 1];
            for (int j = 0; j <= e; j++)
                for (int k = 0; k <= e; k++)
                    s[j, k] = r;

            s[f, g] = 0;
            var t = new Y<Z>();
            t.B(new Z(0, f, g));
            long u = -1;

            while (t.A > 0)
            {
                var v = t.C();
                long w = v.a;
                int y = v.b;
                int z = v.c;

                if (w != s[y, z])
                    continue;

                if (y == z && o[y])
                {
                    u = w;
                    break;
                }

                foreach (var aa in i[y])
                {
                    foreach (var bb in n[z])
                    {
                        long cc = w + Math.Abs(aa - bb);
                        if (cc < s[aa, bb])
                        {
                            s[aa, bb] = cc;
                            t.B(new Z(cc, aa, bb));
                        }
                    }
                }
            }

            c.Add(u.ToString());
        }

        Console.WriteLine(string.Join("\n", c));
    }
}

class Y<T> where T : IComparable<T>
{
    private List<T> a;

    public Y()
    {
        a = new List<T>();
    }

    public int A => a.Count;

    public void B(T b)
    {
        a.Add(b);
        int c = a.Count - 1;
        while (c > 0)
        {
            int d = (c - 1) / 2;
            if (a[c].CompareTo(a[d]) >= 0)
                break;
            T e = a[c];
            a[c] = a[d];
            a[d] = e;
            c = d;
        }
    }

    public T C()
    {
        int a = this.a.Count - 1;
        T b = this.a[0];
        this.a[0] = this.a[a];
        this.a.RemoveAt(a);

        --a;
        int c = 0;
        while (true)
        {
            int d = c * 2 + 1;
            if (d > a) break;
            int e = d + 1;
            if (e <= a && this.a[e].CompareTo(this.a[d]) < 0)
                d = e;
            if (this.a[c].CompareTo(this.a[d]) <= 0)
                break;
            T f = this.a[c];
            this.a[c] = this.a[d];
            this.a[d] = f;
            c = d;
        }
        return b;
    }
}