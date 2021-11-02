fallocate -l 50M lofs.img
sudo losetup -f lofs.img 
sudo mkfs.ext4 /dev/loop0
mkdir lofsdisk
sudo mount /dev/loop0 lofsdisk

