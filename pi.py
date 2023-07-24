while 0 == 0:
    import random  
    
    num_samples = int(input("请输入样本数量："))  
    
    def estimate_pi(num_samples):  
        num_points_in_circle = 0  
        for i in range(num_samples):  
            x = random.uniform(-1, 1)  
            y = random.uniform(-1, 1)  
            distance = x**2 + y**2  
            if distance <= 1:  
                num_points_in_circle += 1  
        return 4 * num_points_in_circle / num_samples  
    
    print("估计圆周率为：", estimate_pi(num_samples))
