require 'open3'

#初期化処理・データ取得準備・・・実行ファイル群削除    
    Open3.popen3("")
    data_quantity = 1024
    swap_probability = 0.5
    gap = 1
    puts '[フィボナッチ数列・加算回数比較]'
    sleep(5)
    puts 'Processsing...'
    File.open("res_shell_cnt1.1-2.0.csv", "w") do |file|
        1.1.step(2.0, 0.01) { |cnt|
            puts(cnt)
            stdin, stdout, wait_thread = Open3.popen3("echo '#{data_quantity}' | ./a.out")

            stdout.each do |line|
                file.puts(line)
            end
        }
    end

