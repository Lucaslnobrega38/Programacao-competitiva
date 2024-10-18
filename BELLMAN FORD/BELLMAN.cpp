void ford(int source, grafoaux &aux)
    {
        vector<long long> dists(size,LONG_LONG_MAX);
        dists[source] = 0;

        for (int i=0;i<size;i++)
        for (edge e : edges)
        {
            if (dists[e.de] == LONG_LONG_MAX) continue;

            if (dists[e.para] > dists[e.de] + e.peso)
                dists[e.para] = dists[e.de] + e.peso;
        }

        for (edge e : edges)
        {
            if (dists[e.de] == LONG_LONG_MAX) continue;

            if (dists[e.para] > dists[e.de] + e.peso && aux.acessible[e.para])
            {
                cout << -1;
                return;
            }
        }

        cout << -dists[size-1];
    }