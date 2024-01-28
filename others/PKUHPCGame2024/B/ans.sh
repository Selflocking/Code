
# 提取 ssh 流量, -t 限制时间30min。 --cpus-per-task 每个任务16cpu, 用于提高内存
srun --cpus-per-task 16 -t 30 tshark -r /lustre/shared_data/potato_kingdom_univ_trad_cluster/pcaps/0.pcap -Y ssh -w 0.ssh.pcap && \
                        tshark -r /lustre/shared_data/potato_kingdom_univ_trad_cluster/pcaps/1.pcap -Y ssh -w 1.ssh.pcap && \
                        tshark -r /lustre/shared_data/potato_kingdom_univ_trad_cluster/pcaps/2.pcap -Y ssh -w 2.ssh.pcap && \
                        tshark -r /lustre/shared_data/potato_kingdom_univ_trad_cluster/pcaps/3.pcap -Y ssh -w 3.ssh.pcap && \
                        tshark -r /lustre/shared_data/potato_kingdom_univ_trad_cluster/pcaps/4.pcap -Y ssh -w 4.ssh.pcap && \
                        tshark -r /lustre/shared_data/potato_kingdom_univ_trad_cluster/pcaps/5.pcap -Y ssh -w 5.ssh.pcap && \
                        tshark -r /lustre/shared_data/potato_kingdom_univ_trad_cluster/pcaps/6.pcap -Y ssh -w 6.ssh.pcap && \
                        tshark -r /lustre/shared_data/potato_kingdom_univ_trad_cluster/pcaps/7.pcap -Y ssh -w 7.ssh.pcap && \
                        tshark -r /lustre/shared_data/potato_kingdom_univ_trad_cluster/pcaps/8.pcap -Y ssh -w 8.ssh.pcap && \
                        tshark -r /lustre/shared_data/potato_kingdom_univ_trad_cluster/pcaps/9.pcap -Y ssh -w 9.ssh.pcap && \
                        tshark -r /lustre/shared_data/potato_kingdom_univ_trad_cluster/pcaps/10.pcap -Y ssh -w 10.ssh.pcap && \
                        tshark -r /lustre/shared_data/potato_kingdom_univ_trad_cluster/pcaps/11.pcap -Y ssh -w 11.ssh.pcap && \
                        tshark -r /lustre/shared_data/potato_kingdom_univ_trad_cluster/pcaps/12.pcap -Y ssh -w 12.ssh.pcap && \
                        tshark -r /lustre/shared_data/potato_kingdom_univ_trad_cluster/pcaps/13.pcap -Y ssh -w 13.ssh.pcap && \
                        tshark -r /lustre/shared_data/potato_kingdom_univ_trad_cluster/pcaps/14.pcap -Y ssh -w 14.ssh.pcap && \
                        tshark -r /lustre/shared_data/potato_kingdom_univ_trad_cluster/pcaps/15.pcap -Y ssh -w 15.ssh.pcap

# 合并 pcap
srun mergecap -w merged.pcap *.ssh.pcap

# 交给 quantum-cracker
srun -N4 --ntasks-per-node 4 /usr/bin/quantum-cracker merged.pcap

# 获取 job id
sacct -u $(whoami) --format JobID | tail
