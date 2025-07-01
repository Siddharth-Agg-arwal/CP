using System;
using System.Collections.Generic;
using System.Linq;

class DSU
{
    private int[] p, sz;
    private long[] best;
    private const long INF = (long)4e18;

    public DSU(int n)
    {
        p = new int[n + 1];
        sz = new int[n + 1];
        best = new long[n + 1];
        for (int i = 0; i <= n; i++)
        {
            p[i] = i;
            sz[i] = 1;
            best[i] = INF;
        }
    }

    public int Find(int v)
    {
        if (p[v] != v)
            p[v] = Find(p[v]);
        return p[v];
    }

    public void Unite(int a, int b, long w)
    {
        a = Find(a);
        b = Find(b);
        if (a == b)
        {
            best[a] = Math.Min(best[a], w);
            return;
        }
        if (sz[a] < sz[b])
        {
            var temp = a;
            a = b;
            b = temp;
        }
        p[b] = a;
        sz[a] += sz[b];
        best[a] = Math.Min(Math.Min(best[a], best[b]), w);
    }

    public long GetBest(int v)
    {
        return best[Find(v)];
    }

    public int GetParent(int v)
    {
        return Find(v);
    }
}

class Program
{
    static void Main()
    {
        int T = int.Parse(Console.ReadLine());

        for (int t = 0; t < T; t++)
        {
            var parts = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int n = parts[0], m = parts[1];

            var edges = new List<(int u, int v, long w)>();
            for (int i = 0; i < m; i++)
            {
                var edgeParts = Console.ReadLine().Split();
                int u = int.Parse(edgeParts[0]);
                int v = int.Parse(edgeParts[1]);
                long w = long.Parse(edgeParts[2]);
                edges.Add((u, v, w));
            }

            edges.Sort((a, b) => a.w.CompareTo(b.w));

            var dsu = new DSU(n);
            long ans = (long)4e18;

            foreach (var ed in edges)
            {
                dsu.Unite(ed.u, ed.v, ed.w);
                if (dsu.GetParent(1) == dsu.GetParent(n))
                {
                    long cand = ed.w + dsu.GetBest(1);
                    ans = Math.Min(ans, cand);
                }
            }

            Console.WriteLine(ans);
        }
    }
}
