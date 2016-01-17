def chknum(n,x)
    return "#{x}.#{n}"
end

def und(input)

    array = input
    array_2 = Array.new
    count = 0
    i = 0
    checkn = 0

    array.each_with_index do |value,index|
        i = index;
        loop do
            checkn += 1
            i += 1
            index += 1
        count += 1
        break if value != array[i]
        end
        array_2 << chknum(value, count)
        break if checkn == array.length
        count = 0;
        i = 0;
    end

    return array_2
end

sux = [1,2,1,1]

2.times do
    sux = und(sux)
end


sux.each do |x|
    print x
end
