#!/usr/bin/python3

import matplotlib.pyplot as plt


if __name__ == "__main__":
    hull_10 = {"file_name" : "hull_10", "label" : "10% in hull"}
    hull_30 = {"file_name" : "hull_30", "label" : "30% in hull"}
    hull_50 = {"file_name" : "hull_50", "label" : "50% in hull"}
    hull_70 = {"file_name" : "hull_70", "label" : "70% in hull"}
    hull_90 = {"file_name" : "hull_90", "label" : "90% in hull"}
    random = {"file_name" : "random", "label" : "random"}
    distros = [hull_10, hull_30, hull_50, hull_70, hull_90, random]
    points = [100, 1000, 10000, 100000, 1000000]

    for dist in distros:
        gw_times = []
        for n in points:
            gw_time = f"../samples/times/{dist['file_name']}/GW_{str(n)}.txt"
            with open(gw_time, 'r') as f:
                lst = f.readlines()
                tmp_time = float(lst[0].strip())
                gw_times += [tmp_time]
        gs_times = []
        for n in points:
            gs_time = f"../samples/times/{dist['file_name']}/GH_{str(n)}.txt"
            with open(gs_time, 'r') as f:
                lst = f.readlines()
                tmp_time = float(lst[0].strip())
                gs_times += [tmp_time]
        dist['gw_times'] = gw_times
        dist['gs_times'] = gs_times

    for dist in distros:
        fig, ax = plt.subplots()
        ax.set_xscale('log')
        #ax.set_yscale('log')

        plt.title("Tiempos de ejecución de convex hull\ncon dist: " + dist["label"])
        plt.ylabel("Tiempo de ejecución [ms]")
        plt.xlabel("Número de puntos")
        ax.plot(points, dist['gw_times'], 'r', label = "Gift Wrapping")
        ax.plot(points, dist['gs_times'], 'b', label = "Graham Scan")
        plt.legend()

        fig.savefig(f"{dist['file_name']}_gf_vs_gs.png")


        fig, ax = plt.subplots()
        ax.set_xscale('log')
        ax.set_yscale('log')

        plt.title("Tiempos de ejecución de convex hull\ncon dist: " + dist["label"])
        plt.ylabel("Tiempo de ejecución [ms]")
        plt.xlabel("Número de puntos")
        ax.plot(points, dist['gw_times'], 'r', label = "Gift Wrapping")
        ax.plot(points, dist['gs_times'], 'b', label = "Graham Scan")
        plt.legend()

        fig.savefig(f"{dist['file_name']}_gf_vs_gs_logs.png")


    fig, ax = plt.subplots()
    for dist in distros:
        ax.set_xscale('log')
        #ax.set_yscale('log')
        plt.title("Evolucion de los tiempos de ejecución del algoritmo Gift Wrapping \n de las distintas dsitrbuciones de puntos")
        plt.ylabel("Tiempo de ejecución [ms]")
        plt.xlabel("Número de puntos")
        ax.plot(points, dist['gw_times'], label = dist['label'])
        plt.legend()

    fig.savefig("gw_evolution.png")

    fig, ax = plt.subplots()
    for dist in distros:
        ax.set_xscale('log')
        ax.set_yscale('log')
        plt.title("Evolucion de los tiempos de ejecución del algoritmo Gift Wrapping \n de las distintas dsitrbuciones de puntos")
        plt.ylabel("Tiempo de ejecución [ms]")
        plt.xlabel("Número de puntos")
        ax.plot(points, dist['gw_times'], label = dist['label'])
        plt.legend()

    fig.savefig("gw_evolution_log.png")

    fig, ax = plt.subplots()
    for dist in distros:
        ax.set_xscale('log')
        #ax.set_yscale('log')
        plt.title("Evolucion de los tiempos de ejecución del algoritmo Graham Scan \n de las distintas dsitrbuciones de puntos")
        plt.ylabel("Tiempo de ejecución [ms]")
        plt.xlabel("Número de puntos")
        ax.plot(points, dist['gs_times'], label = dist['label'])
        plt.legend()

    fig.savefig("gs_evolution.png")

    fig, ax = plt.subplots()
    for dist in distros:
        ax.set_xscale('log')
        ax.set_yscale('log')
        plt.title("Evolucion de los tiempos de ejecución del algoritmo Graham Scan \n de las distintas dsitrbuciones de puntos")
        plt.ylabel("Tiempo de ejecución [ms]")
        plt.xlabel("Número de puntos")
        ax.plot(points, dist['gs_times'], label = dist['label'])
        plt.legend()

    fig.savefig("gs_evolution_log.png")
