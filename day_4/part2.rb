require 'digest'

class String
    def initial
        self[0,6]
    end
end

md5 = Digest::MD5.new
md5.hexdigest
i = 0;

while(i)
    md5.reset
    md5.update "bgvyzdsv#{i}"
    if md5.to_s.initial == "000000"
        puts (md5.to_s)
        puts "counter: " + " " + i.to_s
        break
    end
    i += 1
end
